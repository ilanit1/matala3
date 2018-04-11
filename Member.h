#include <iostream>
#include <map>
#include <iterator>
using namespace std;

class Member
{
    
public:

      int num;                            //every member get a uniqe number
      map<int,Member*> mapOfFollowing;    //the members that our member follow after
      map<int,Member*> mapOfFollowers;    //the members that follow after our member

	Member();
	~Member();
	void follow(Member &another);
	void unfollow(Member &another);
	static int count();
	int numFollowers(){
      return mapOfFollowers.size();
    }
    int numFollowing(){
      return mapOfFollowing.size();
    }
};

