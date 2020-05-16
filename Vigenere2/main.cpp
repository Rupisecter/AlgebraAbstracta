#include <iostream>
#include <string>
#include "clase.h"
using namespace std;

int main() 
{
  Vigenere cypher;
  string msg,cmsg,dmsg;
  //msg="To investigate the process of reasoning with an interactive diagram, we recorded eye movements and mouse clicks of 28 users as they investigated social relationships in a 313-node network diagram";
  //msg="-vpYoSxvlxhYVt l suxFM2MxHmjSxLY4hjOc0Xuo78lg-pR6AGoJkoKWmyeIOLi-F2wtJmySwRA8z1RrjNjjbe9,qlJaDrrrm QZeAczyFkX 2rBBwzAsKY8h7Gc8Fbo8d9gFzYQ-rfwm G6xprssLmSCfs EtuJeQGfmrN6qBihfb7dMyC3IDvvGdGVkAaCG";
  msg="lDG EBeDRZgmFwY3lhGArM3djRreEuld3oQCqDzGwvRY m-QGZxhzncR9u5Z48-al9fW0LmQImc-PUepMwWQCpwGeK5mkRr0M7ulhqUvGuCqcxQforMkyayvmCsY1rrS84XucmoaUIqyt-eqY7oowsJavhtntGfmjG9fRucmt60k9lSvoqCfnqFMM1oBlvaEi9d";
  //getline(cin,msg);
  //cmsg=cypher.cifrarabc(msg);
  dmsg=cypher.descifrarabc(msg);
  //cout<<cmsg<<endl;
  cout<<dmsg<<endl;


}