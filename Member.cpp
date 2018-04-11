#include "Member.h"

static int counter=0;     //num of members in our social network

Member::Member()      //member constructor
{
   counter++;
   this->num=counter;
  
}
 
Member::~Member(){    //member distructor
    
    counter--;
   
     map<int,Member*>::iterator it;

     for(it=mapOfFollowing.begin();it!=mapOfFollowing.end();it++){                      //pass over all my following map
         it->second->mapOfFollowers.erase(it->second->mapOfFollowers.find(this->num));   //delete my member from each member's followers map
         mapOfFollowing.erase(it);                                                        //delete the member from my following map
     }
     
     for(it=mapOfFollowers.begin();it!=mapOfFollowers.end();it++){                     //pass over all my followers map
         it->second->mapOfFollowing.erase(it->second->mapOfFollowing.find(this->num));  //delete my member from each member's followimg map
    }
}

void Member::follow(Member &x){
   
   if(this->num!=x.num){                                             //if this member is not my member
       if(mapOfFollowing.find(x.num) == mapOfFollowing.end()){       //if i still no follow him 
           mapOfFollowing.insert(make_pair(x.num,&x));               //add him to my following map
           x.mapOfFollowers.insert(make_pair(this->num,this));       //add me to his followers map
       }
   }
}

void Member::unfollow(Member &x){
    
  if(this->num!=x.num){                                               //if this member is not my member
     if (x.mapOfFollowers.find(this->num)!=x.mapOfFollowers.end()){   //if i do follow him
         x.mapOfFollowers.erase(x.mapOfFollowers.find(this->num));    //delete me from his followers map
         mapOfFollowing.erase(mapOfFollowing.find(x.num));            //delete him from my following map
     }
  }

}

int Member::count(){
    return counter;
}
