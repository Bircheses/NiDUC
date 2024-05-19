#include <iostream>
#include <vector>

using namespace std;

void showVector(vector<int>& vec);
vector<int> polynomialDivison(vector<int>& divisor, vector<int>& dividend);
vector<int> coder_15_7(vector<int>& information);
vector<int> coder_15_5(vector<int>& information);

int main() {
    vector<int> information = {1,0,1,1,1,0,1};
    vector<int> coded_information = coder_15_7(information);
    showVector(coded_information);
    information = {1,0,1,1,0};
    coded_information = coder_15_5(information);
    showVector(coded_information);
    return 0;
}

vector<int> polynomialDivison(vector<int>& divisor, vector<int>& dividend){
    vector<int> quotient, remainder;
    quotient.resize(dividend.size()-divisor.size()+1);
    copy(dividend.begin(), dividend.end(), back_inserter(remainder));
    while(remainder.size()>=divisor.size()) {
        quotient[quotient.size()-(remainder.size()-divisor.size())-1]=1;
        for (int i = 0; i < divisor.size(); i++) remainder[i] = (remainder[i] + divisor[i]) % 2;
        do remainder.erase(remainder.begin());
        while (remainder[0]==0 && !remainder.empty());
    }
    return remainder;
}

void showVector(vector<int>& vec){
    for(int number:vec) cout << number;
    cout << endl;
}

vector<int> coder_15_7(vector<int>& information){
    vector<int> generator_polynomial = {1,1,1,0,1,0,0,0,1};
    for(int i=0; i<8; i++) information.push_back(0);
    vector<int> coded_information;
    coded_information.resize(information.size());
    vector<int> remainder = polynomialDivison(generator_polynomial, information);
    for(int i=0; i<=information.size(); i++){
        if(i<=remainder.size()) coded_information[coded_information.size()-i]=(information[information.size()-i]+remainder[remainder.size()-i])%2;
        else coded_information[coded_information.size()-i]=information[information.size()-i];
    }
    return coded_information;
}

vector<int> coder_15_5(vector<int>& information){
    vector<int> generator_polynomial = {1,0,1,0,0,1,1,0,1,1,1};
    for(int i=0; i<10; i++) information.push_back(0);
    vector<int> coded_information;
    coded_information.resize(information.size());
    vector<int> remainder = polynomialDivison(generator_polynomial, information);
    for(int i=0; i<=information.size(); i++){
        if(i<=remainder.size()) coded_information[coded_information.size()-i]=(information[information.size()-i]+remainder[remainder.size()-i])%2;
        else coded_information[coded_information.size()-i]=information[information.size()-i];
    }
    return coded_information;
}