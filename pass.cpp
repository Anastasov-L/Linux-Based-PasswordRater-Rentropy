#include <iostream>
#include <string>

using namespace std;

void firstName(string &firstN){
    getline(cin,firstN);
}

void lastName(string &lastN){
    getline(cin,lastN);
}

string birthDay(string &birthY, string &birthM, string &birthD){
    string input;

    getline(cin,input);

    if(input.size() >= 8 && input.size() <= 10 ){
        birthY = string(1,input.at(0)) + input.at(1) + input.at(2) + input.at(3);

        if(input.at(6)!= '/'){
           birthM = string(1,input.at(5)) + input.at(6);
            if(input.size()-8 == 1){                
                birthD = input.at(8);
            }else{
                birthD = string(1,input.at(8)) + input.at(9);
            }
        }else{
            birthM = input.at(5);    
            if(input.size()-7 == 1){
                birthD = input.at(7);
            }else{
                birthD = string(1,input.at(7)) + input.at(8);
            }
        }


        return input;
    }else{
        input = "badInput";
        return input;
    }

}


int main() {
   string firstN, lastN, birthY, birthM, birthD;
   firstName(firstN);

   lastName(lastN);

 string outcome =  birthDay(birthY, birthM, birthD);
 cout << birthY << " " << birthM << " " << birthD<<endl;
 cout << outcome;

 
    return 0;
}