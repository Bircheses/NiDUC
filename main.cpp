#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> generator_15_7 = {1,1,1,0,1,0,0,0,1};
const vector<int> generator_15_5 = {1,0,1,0,0,1,1,0,1,1,1};

void showVector(vector<int>& vec);
vector<int> polynomialDivison(const vector<int>& divisor, vector<int>& dividend);
vector<int> coder_15_7(vector<int>& information);
vector<int> decoder_15_7(vector<int>& coded_information);
vector<int> coder_15_5(vector<int>& information);
vector<int> decoder_15_5(vector<int>& coded_information);

int main() {
    vector<int> information1 = {1,0,1,1,1,0,1};
    vector<int> coded_information1 = coder_15_7(information1);
    showVector(coded_information1);
    vector<int> decoded_information1 = decoder_15_7(coded_information1);
    showVector(decoded_information1);

    vector<int> information2 = {1,0,1,1,0};
    vector<int> coded_information2 = coder_15_5(information2);
    showVector(coded_information2);
    vector<int> decoded_information2 = decoder_15_5(coded_information2);
    showVector(decoded_information2);

    return 0;
}

vector<int> polynomialDivison(const vector<int>& divisor, vector<int>& dividend){
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
    for(int i=0; i<8; i++) information.push_back(0);
    vector<int> coded_information;
    coded_information.resize(information.size());
    vector<int> remainder = polynomialDivison(generator_15_7, information);
    for(int i=0; i<=information.size(); i++){
        if(i<=remainder.size()) coded_information[coded_information.size()-i]=(information[information.size()-i]+remainder[remainder.size()-i])%2;
        else coded_information[coded_information.size()-i]=information[information.size()-i];
    }
    return coded_information;
}

vector<int> decoder_15_7(vector<int>& coded_information){
    vector<int> decoded_information;
    vector<int> syndrome = polynomialDivison(generator_15_7, coded_information);
    int wage = count(syndrome.begin(),syndrome.end(),1);
    if(wage == 0){
        copy(coded_information.begin(),coded_information.begin()+7, back_inserter(decoded_information));
        return decoded_information;
    }else if(wage <= 2){
        for(int i=0; i<syndrome.size(); i++){
            coded_information[coded_information.size()-i]=(*(coded_information.rend()-i)+*(syndrome.rend()-i))%2;
        }
        copy(coded_information.begin(),coded_information.begin()+7, back_inserter(decoded_information));
        return decoded_information;
    }else{
        int j = 0;
        while(wage > 2) {
            rotate(coded_information.rbegin(), coded_information.rbegin() + 1, coded_information.rend());
            syndrome = polynomialDivison(generator_15_7, coded_information);
            wage = count(syndrome.begin(),syndrome.end(),1);
            j++;
        }
        for(int i=1; i<=syndrome.size(); i++){
            coded_information[coded_information.size()-i]=(coded_information[coded_information.size()-i]+syndrome[syndrome.size()-i])%2;
        }
        while(j>0){
            rotate(coded_information.begin(), coded_information.begin()+1, coded_information.end());
            j--;
        }
        copy(coded_information.begin(),coded_information.begin()+7, back_inserter(decoded_information));
        return decoded_information;
    }
}

vector<int> coder_15_5(vector<int>& information){
    for(int i=0; i<10; i++) information.push_back(0);
    vector<int> coded_information;
    coded_information.resize(information.size());
    vector<int> remainder = polynomialDivison(generator_15_5, information);
    for(int i=0; i<=information.size(); i++){
        if(i<=remainder.size()) coded_information[coded_information.size()-i]=(information[information.size()-i]+remainder[remainder.size()-i])%2;
        else coded_information[coded_information.size()-i]=information[information.size()-i];
    }
    return coded_information;
}

vector<int> decoder_15_5(vector<int>& coded_information){
    vector<int> decoded_information;
    vector<int> syndrome = polynomialDivison(generator_15_5, coded_information);
    int wage = count(syndrome.begin(),syndrome.end(),1);
    if(wage == 0){
        copy(coded_information.begin(),coded_information.begin()+5, back_inserter(decoded_information));
        return decoded_information;
    }else if(wage <= 3){
        for(int i=0; i<syndrome.size(); i++){
            coded_information[coded_information.size()-i]=(*(coded_information.rend()-i)+*(syndrome.rend()-i))%2;
        }
        copy(coded_information.begin(),coded_information.begin()+5, back_inserter(decoded_information));
        return decoded_information;
    }else{
        int j = 0;
        while(wage > 3) {
            rotate(coded_information.rbegin(), coded_information.rbegin() + 1, coded_information.rend());
            syndrome = polynomialDivison(generator_15_5, coded_information);
            wage = count(syndrome.begin(),syndrome.end(),1);
            j++;
        }
        for(int i=1; i<=syndrome.size(); i++){
            coded_information[coded_information.size()-i]=(coded_information[coded_information.size()-i]+syndrome[syndrome.size()-i])%2;
        }
        while(j>0){
            rotate(coded_information.begin(), coded_information.begin()+1, coded_information.end());
            j--;
        }
        copy(coded_information.begin(),coded_information.begin()+5, back_inserter(decoded_information));
        return decoded_information;
    }
}