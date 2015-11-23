#include "grid.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isRouteWellFormed(string route);
bool isValidChar(char c);
int navigateSegment(int r, int c, char dir, int maxSteps);
int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps);
int navigateSegmentEast(int r, int c);

//& is address, * is unwrap.
//nsteps hence references the value of whatever is passed to it
//aka its address is that which is passed to it

//note to self : think about boundary cases (empty string, input 0)
//access element in string(array) think abou tall possibility of positions
//dont access out of bounds arrays

int main() {
  setSize(3,4);
  setWall(1,4);
  setWall(2,2);
  setWall(3,2);

  draw(3,3,1,1);

  int testSteps = 0;
  //tests for routeTest
  assert(isRouteWellFormed("string route") == false);
  assert(isRouteWellFormed("N2eE01n0e2e1") == true);
  assert(isRouteWellFormed("W42") == true);
  assert(isRouteWellFormed("3sn") == false);
  assert(isRouteWellFormed("e1x") == false);
  assert(isRouteWellFormed("N144") == false);
  assert(isRouteWellFormed("w2+n3") == false);
  assert(isRouteWellFormed("11123123123e") == false);
  assert(isRouteWellFormed("ewewewewewewewe") == true);

  //all err cases
  assert(navigateSegment(1, -1, 'e', 5) == -1);
  assert(navigateSegment(-1, 1, 'e', 5) == -1);
  assert(navigateSegment(1, -1, 'o', 5) == -1);
  assert(navigateSegment(2, 2, 'e', 5) == -1);
  assert(navigateSegment(7, 1, 's', 5) == -1);
  assert(navigateSegment(1, 7, 's', 5) == -1);
  assert(navigateSegment(1, 7, 's', -5) == -1);

  assert(navigateSegment(1, 1, 'e', 5) == 2);
  assert(navigateSegment(1, 1, 's', 5) == 2);
  assert(navigateSegment(1, 1, 'e', 1) == 1);
  assert(navigateSegment(1, 1, 'e', 2) == 2);
  assert(navigateSegment(1, 1, 'N', 3) == 0);
  assert(navigateSegment(2, 1, 'e', 3) == 0);
  assert(navigateSegment(2, 4, 'w', 3) == 1);
  assert(navigateSegment(3, 3, 's', 3) == 0);
  assert(navigateSegment(1, 2, 'N', 2) == 0);
  assert(navigateSegment(3, 1, 'e', 5) == 0);
  assert(navigateSegment(2, 3, 'w', 5) == 0);
  assert(navigateSegment(1, 2, 's', 5) == 0);
  assert(navigateSegment(1, 3, 's', 5) == 2);
  assert(navigateSegment(1, 3, 's', 0) == 0);

  assert(navigateRoute(3, 4, 3, 1, "u2", testSteps) == 2);
  assert(navigateRoute(1, 1, 1, 4, "e2", testSteps) == 2);
  assert(navigateRoute(1, 1, 1, 3, "e9", testSteps) == 3);
  assert(navigateRoute(1, 2, 3, 1, "s", testSteps) == 3);
  assert(navigateRoute(3, 4, 3, 1, "w2", testSteps) == 3);

  assert(navigateRoute(1, 1, 3, 4, "e2se", testSteps) == 1);
  assert(navigateRoute(1, 1, 3, 4, "e2ses", testSteps) == 0);
  assert(navigateRoute(1, 1, 3, 4, "e02s01n0es", testSteps) == 0);
  assert(navigateRoute(1, 1, 3, 4, "e2w2e2s01n0es", testSteps) == 0);
  assert(navigateRoute(3, 1, 3, 4, "n2e2s2e", testSteps) == 0);

  cerr << "All tests succeeded" << endl;

}

bool isValidChar(char c) {
  if(c == 'N' || c == 'n' || c == 'S' || c == 's' || c == 'E' || c == 'e' || c == 'W' || c == 'w') {
    return true;
  } else {
    return false;
  }
}

bool isRouteWellFormed(string route) {
  //loop through entire string to identify weird inputs
  //TBD: consider parsing route here?
  int digitCount = 0;

  for(int i=0;i<route.size();i++) {
    if(isValidChar(route[i])) {
      digitCount = 0;
    } else if (isdigit(route[i]) && i!=0) {
      digitCount++;
      if (digitCount == 3) {
       cerr << "One of the directional values is too big!!" << endl;
       return false;
      }
    } else {
      cerr << "Invalid character found in position " << i << " of entered string" << endl;
      return false;
    }
  }
  return true;
}

//validate any coords
bool validateCoords(int r, int c) {
  if(r < 0 || c < 0 || r > getRows() || c > getCols() || isWall(r,c))
    return false;
  return true;
}

/*
This function determines the number of steps a robot starting at
position (r,c) could take in the direction indicated by dir.
In the normal case, when this function is called, (r,c)
is an empty grid position, dir is one of the letters N, E, S, or W,
in either upper or lower case, and maxSteps is the proposed number
of steps to take in the indicated direction. In this case, if the
robot starting at (r,c) could indeed take that number of steps in that
direction without moving to a cell containing a wall or running off
the edge of the grid, then the function returns that number of steps;
otherwise, the function returns the maximum number of valid steps
in that direction the robot could take (which will be less than the
value of maxSteps, and might even be zero). If (r,c) is not a valid
empty grid position, or if dir is an invalid direction character, or
if maxSteps is negative, the function returns −1.
*/
int navigateSegment(int r, int c, char dir, int maxSteps) {
  //validate inputs
  if(maxSteps < 0 || !isValidChar(dir) || !validateCoords(r, c)) {
    cerr << "navigateSegment received invalid input" << endl;
    return -1;
  } else if (maxSteps == 0) {
    //if steps is 0
    return 0;
  }

  int segs = 0;

  switch(dir) {
    case 'e':
    case 'E':
      //check from the first item on the right, until right bound
      for(int i = c + 1; i <= getCols(); i++) {
        if(isWall(r, i)) {
          break;
        } else {
          segs++;
        }
      }
      break;
    case 'w':
    case 'W':
      //check from first item on the left,
      for(int i = c - 1; i >= 1; i--) {
        if(isWall(r, i)) {
          break;
        } else {
          segs++;
        }
      }
      break;
    case 's':
    case 'S':
      for(int i = r + 1; i <= getRows(); i++) {
        if(isWall(i, c)) {
          break;
        } else {
          segs++;
        }
      }
      break;
    case 'n':
    case 'N':
      for(int i = r - 1; i >= 1; i--) {
        if(isWall(i, c)) {
          break;
        } else {
          segs++;
        }
      }
      break;
  }

  if(segs >= maxSteps) {
    //total possible steps more than maxSteps, only return maxSteps
    return maxSteps;
  } else {
    return segs;
  }

}

/*
This function determines the number of steps a robot starting at
position (sr,sc) takes when following the indicated route, which
should lead to the end position (er,ec). In the normal case, (sr,sc)
and (er,ec) are empty grid positions and route is a syntactically valid
navigable route. In this case, the function sets nsteps to the number of
steps a robot starting at (sr,sc) takes when navigating the complete route,
and returns 0 if the robot ends up at (er,ec), or 1 otherwise. If (sr,sc)
or (er,ec) are not valid empty grid positions or if route is not syntactically
valid, the function returns 2 and leaves nsteps unchanged. If (sr,sc) and
(er,ec) are empty grid positions and route is syntactically valid, but
the robot could not navigate the complete route without moving to a cell
containing a wall or running off the edge of the grid, then the function
returns 3 and sets nsteps to the maximum number of steps that the robot
can take along the route (which might be 0). You must not assume that
nsteps has any particular value at the time this function is entered.
*/
int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps) {
  if(!validateCoords(sr, sc) || !validateCoords(er, ec) || !isRouteWellFormed(route)) {
    cerr << "Route params invalid" << endl;
    return 2;
  }

  nsteps = 0;
  char dir;
  int steps;


  //go through the string - assume syntactically valid
  for(int i = 0; i < route.size(); i++) {
    if(isalpha(route[i])) {
      dir = route[i];

      if(i+1<route.size() && isdigit(route[i+1])) {
        //the next one is a digit!
        int first = route[i+1] - '0';
        if(i+2<route.size() && isdigit(route[i+2])) {
          //the next one is a digit again!
          steps = first * 10 + route[i+2] - '0';
        } else {
          steps = first;
        }
      } else {
        //the next one is a letter again, or we are a letter at the end of str.
        steps = 1;
      }
      //ill only care when its a letter, ignore numbers
      int navi = navigateSegment(sr, sc, dir, steps);

      if(steps > navi) {
        //walk too many steps!! fail.
        //adds maximum possible steps from the path to nsteps
        nsteps += navi;
        return 3;
      } else {
        //navi is good. increment steps, update coords
        nsteps += navi;
        switch(dir) {
          case 'e':
          case 'E':
            sc += steps;
            break;
          case 'w':
          case 'W':
            sc -= steps;
            break;
          case 'N':
          case 'n':
            sr -= steps;
            break;
          case 'S':
          case 's':
            sr += steps;
            break;
        }
      }
    }
  }
  //im done consuming the route, and has not erred
  //if im at the end, return ok
  if (sr == er && sc == ec) {
    return 0;
  } else {
    return 1;
  }

}
