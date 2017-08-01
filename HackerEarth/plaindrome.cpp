
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<long int> palindrome;
// vector<long int> superdromes;

// int createPalindrome(int input, int b, bool isOdd){
//     int n = input;
//     int palin = input;

//     if (isOdd)
//         n /= b;
//     while (n > 0){
//         palin = palin * b + (n % b);
//         n /= b;
//     }
//     return palin;
// }
 
// void generatePaldindromes(int n){
//     int number;
//     for (int j = 0; j < 2; j++){
//         int i = 1;
//         while ((number = createPalindrome(i, 10, j % 2)) < n){
//             // cout << number << " ";
//             palindrome.push_back(number);
//             i++;
//         }
//     }
// }
 
// bool checkBinPalindrome(int number){
//     vector<int> bin;
//     int r;
//     while(number>0){
//         r = number%2;
//         bin.push_back(r);
//         number /= 2;
//     }
//     int i=0,j=bin.size()-1;
//     while(i<j){
//         if(bin[i] != bin[j]) return false;
//         i++; j--;
//     }
//     return true;
// }

// void generateSuperdromes(){
//     int n = 10000000;
//     generatePaldindromes(n);
//     for(int i=0;i<palindrome.size();i++){
//         if(checkBinPalindrome(palindrome[i])){
//             superdromes.push_back(palindrome[i]);
//             cout<<palindrome[i]<<",";
//         }
//     }
// }

int super[]={1, 3, 5, 7, 9, 33, 99, 313, 585, 717, 7447, 9009, 15351, 32223, 39993, 53235, 53835, 73737, 585585, 1758571, 1934391, 1979791, 3129213, 5071705, 5259525, 5841485};

int main(){
    // generateSuperdromes();
    // sort(super,super+26);
    // cout<<"\nint super[]={";
    // for(int i=0;i<19;i++)
    //     cout<<super[i]<<",";
    // cout<<"};";
    
    int n,t;
    cin>>n;
    while(n-->0){
        cin>>t;
        int i=0;
        while(super[i] <= t) i++;
        cout<<i<<endl;
    }
    return 0;
}