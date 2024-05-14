#include <iostream>
#include <vector>

using namespace std;

void showVector(vector<int>& vec);
void polynomialDivison(vector<int>& divisor, vector<int>& dividend, vector<int>& quotient, vector<int>& remainder);

int main() {
    vector<int> divisor = {1,0,1,1};
    vector<int> dividend = {1,1,0,0,1,0,1};
    vector<int> quotient;
    vector<int> remainder;

    polynomialDivison(divisor, dividend, quotient, remainder);

    return 0;
}

void polynomialDivison(vector<int>& divisor, vector<int>& dividend, vector<int>& quotient, vector<int>& remainder){
    quotient.resize(dividend.size()-divisor.size()+1);
    copy(dividend.begin(), dividend.end(), back_inserter(remainder));

    while(remainder.size()>=divisor.size()) {
        quotient[quotient.size()-(remainder.size()-divisor.size())-1]=1;
        for (int i = 0; i < divisor.size(); i++) remainder[i] = (remainder[i] + divisor[i]) % 2;
        do remainder.erase(remainder.begin());
        while (remainder[0]==0 && !remainder.empty());
    }
    showVector(quotient);
    showVector(remainder);
}

void showVector(vector<int>& vec){
    for(int number:vec) cout << number;
    cout << endl;
}
