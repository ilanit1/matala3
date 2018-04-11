#include "Member.h"

void testFollow(){         //check if follow unction is correct
	
	Member elon,ilanit,roi;
	
	ilanit.follow(ilanit);
	ilanit.follow(roi);
	elon.follow(ilanit);
	roi.follow(elon);
	roi.follow(elon);
	elon.follow(roi);
	
	if(ilanit.numFollowing()==1&&ilanit.numFollowers()==1&&
	   elon.numFollowing()==2&&elon.numFollowers()==1&&
	   roi.numFollowing()==1&&roi.numFollowers()==2)
	   {
	   	cout<<"the function follow is working."<<endl;
	   }
	   
	   else{
	   	
	   	cout<<"error. the fuction follow is not working."<<endl;
	   }
}
 
void testUnfollow(){       //check if unfollow unction is correct
	
	Member elon,ilanit,roi;
	
	ilanit.follow(roi);
	roi.follow(elon);
	elon.follow(roi);
	
	ilanit.unfollow(roi);
	ilanit.unfollow(roi);
	ilanit.unfollow(elon);
	ilanit.unfollow(ilanit);
	roi.unfollow(elon);
	
	if(ilanit.numFollowing()==0&&ilanit.numFollowers()==0&&
	   roi.numFollowing()==0&&roi.numFollowers()==1&&
	   elon.numFollowing()==1&&elon.numFollowers()==0)
	   {
	    cout<<"the function unfollow is working."<<endl;
	   }
	   
	   else{
	   	
	   	cout<<"error. the fuction unfollow is not working."<<endl;
	   }
	   
}


int main() {

	testFollow();
	testUnfollow();

}


