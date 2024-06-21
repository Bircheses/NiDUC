#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

const vector<int> generator_15_7 = {1,1,1,0,1,0,0,0,1};
const vector<int> generator_15_5 = {1,0,1,0,0,1,1,0,1,1,1};
const vector<int> error = {-1};

void showVector(vector<int>& vec);
vector<int> polynomialDivison(const vector<int>& divisor, vector<int>& dividend);
vector<int> coder_15_7(vector<int>& information);
vector<int> decoder_15_7(vector<int>& coded_information);
vector<int> coder_15_5(vector<int>& information);
vector<int> decoder_15_5(vector<int>& coded_information);
int random_info();
vector<int> one_error(vector<int>& coded_information, int first, int last);
vector<int> two_errors(vector<int>& coded_information, int first, int last);
vector<int> three_errors(vector<int>& coded_information, int first, int last);
vector<int> four_errors(vector<int>& coded_information, int first, int last);
vector<int> two_errors_group(vector<int>& coded_information, int first, int last, int length);
vector<int> three_errors_group(vector<int>& coded_information, int first, int last, int length);
vector<int> four_errors_group(vector<int>& coded_information, int first, int last, int length);
bool compare_vectors(vector<int>& input, vector<int>& output);



int main() {
    srand(time(NULL));
    float test_number = 500;
    float correct_decode = 0;

    for (int i = 0; i < test_number; i++){
        cout << "KOD (15,7)\n";
        vector<int> information1 = {0,0,0,0,0,0,0};
        for (int j = 0; j < 7; j++){
            information1[j] = random_info();
        }
        cout << "wektor wejsciowy: ";
        showVector(information1);

        vector<int> coded_information1 = coder_15_7(information1);
        cout << "zakodowany:       ";
        showVector(coded_information1);

        //coded_information1 = one_error(coded_information1, 1, 6);       // 1 blad, cz. inf.
        //coded_information1 = one_error(coded_information1, 7, 14);   // 1 blad, cz. kontr.
        //coded_information1 = two_errors(coded_information1, 1, 6);      // 2 bledy, cz. inf.
        //coded_information1 = two_errors(coded_information1, 7, 14);      // 2 bledy, cz. kontr.
        //coded_information1 = three_errors(coded_information1, 1, 6);       // 3 bledy, cz. inf.
        //coded_information1 = three_errors(coded_information1, 7, 14);   // 3 bledy, cz. kontr.
        //coded_information1 = two_errors_group(coded_information1, 1, 14, 2);      // grupa 2 bledow, dlugosc 2
        //coded_information1 = two_errors_group(coded_information1, 1, 14, 6);      // grupa 2 bledow, dlugosc 6
        //coded_information1 = two_errors_group(coded_information1, 1, 14, 8);      // grupa 2 bledow, dlugosc 8
        //coded_information1 = two_errors_group(coded_information1, 1, 14, 12);       // grupa 2 bledow, dlugosc 12
        //coded_information1 = three_errors_group(coded_information1, 1, 14, 3);      // grupa 3 bledow, dlugosc 3
        //coded_information1 = three_errors_group(coded_information1, 1, 14, 6);      // grupa 3 bledow, dlugosc 6
        //coded_information1 = three_errors_group(coded_information1, 1, 14, 8);      // grupa 3 bledow, dlugosc 8
        //coded_information1 = three_errors_group(coded_information1, 1, 14, 12);      // grupa 3 bledow, dlugosc 12
        cout << "z bledami:        ";
        showVector(coded_information1);

        vector<int> decoded_information1 = decoder_15_7(coded_information1);
        cout << "dekodowany:       ";
        showVector(decoded_information1);

        if (compare_vectors(information1, decoded_information1)){
            correct_decode++;
        }

        cout << "\n";
    }

    cout << "Wykonane testy: " << test_number;
    cout << "\nTesty zakonczone powodzeniem: " << correct_decode;
    cout << "\nSkutecznosc: " << (correct_decode/test_number)*100 << "%\n\n";

    correct_decode = 0;

    for (int i = 0; i < test_number; i++){
        cout << "KOD (15,5)\n";
        vector<int> information2 = {0,0,0,0,0};
        for (int j = 0; j < 5; j++){
            information2[j] = random_info();
        }
        cout << "wektor wejsciowy: ";
        showVector(information2);

        vector<int> coded_information2 = coder_15_5(information2);
        cout << "zakodowany:       ";
        showVector(coded_information2);

        //coded_information2 = one_error(coded_information2, 1, 4);       // 1 blad, cz. inf.
        //coded_information2 = one_error(coded_information2, 5, 14);   // 1 blad, cz. kontr.
        //coded_information2 = two_errors(coded_information2, 1, 4);      // 2 bledy, cz. inf.
        //coded_information2 = two_errors(coded_information2, 5, 14);      // 2 bledy, cz. kontr.
        //coded_information2 = three_errors(coded_information2, 1, 4);       // 3 bledy, cz. inf.
        //coded_information2 = three_errors(coded_information2, 5, 14);   // 3 bledy, cz. kontr.
        //coded_information2 = four_errors(coded_information2, 1, 4);       // 4 bledy, cz. inf.
        //coded_information2 = four_errors(coded_information2, 5, 14);   // 4 bledy, cz. kontr.
        //coded_information2 = two_errors_group(coded_information2, 1, 14, 2);      // grupa 2 bledow, dlugosc 2
        //coded_information2 = two_errors_group(coded_information2, 1, 14, 6);      // grupa 2 bledow, dlugosc 6
        //coded_information2 = two_errors_group(coded_information2, 1, 14, 8);      // grupa 2 bledow, dlugosc 8
        //coded_information2 = two_errors_group(coded_information2, 1, 14, 12);       // grupa 2 bledow, dlugosc 12
        //coded_information2 = three_errors_group(coded_information2, 1, 14, 3);      // grupa 3 bledow, dlugosc 3
        //coded_information2 = three_errors_group(coded_information2, 1, 14, 6);      // grupa 3 bledow, dlugosc 6
        //coded_information2 = three_errors_group(coded_information2, 1, 14, 8);      // grupa 3 bledow, dlugosc 8
        //coded_information2 = three_errors_group(coded_information2, 1, 14, 12);      // grupa 3 bledow, dlugosc 12
        //coded_information2 = four_errors_group(coded_information2, 1, 14, 4);      // grupa 4 bledow, dlugosc 4
        //coded_information2 = four_errors_group(coded_information2, 1, 14, 6);      // grupa 4 bledow, dlugosc 6
        //coded_information2 = four_errors_group(coded_information2, 1, 14, 8);      // grupa 4 bledow, dlugosc 8
        //coded_information2 = four_errors_group(coded_information2, 1, 14, 12);      // grupa 4 bledow, dlugosc 12

        cout << "z bledami:        ";
        showVector(coded_information2);

        vector<int> decoded_information2 = decoder_15_5(coded_information2);
        cout << "dekodowany:       ";
        showVector(decoded_information2);

        if (compare_vectors(information2, decoded_information2)){
            correct_decode++;
        }

        cout << "\n";
    }

    cout << "Wykonane testy: " << test_number;
    cout << "\nTesty zakonczone powodzeniem: " << correct_decode;
    cout << "\nSkutecznosc: " << (correct_decode/test_number)*100 << "%";

    return 0;
}

int random_info(){
    return (rand()%2);
}

bool compare_vectors(vector<int>& input, vector<int>& output){
    int len = min(input.size(), output.size());
    for (int j=0; j<len; j++){
        if (input[j]!=output[j]){
            return false;
        }
    }
    return true;
}

vector<int> one_error(vector<int>& coded_information, int first, int last){
    int range = last - first + 1;
    int error_index = (rand()%range)+first;

    if (coded_information[error_index] == 0){
        coded_information[error_index] = 1;
    } else {
        coded_information[error_index] = 0;
    }

    return coded_information;
}

vector<int> two_errors(vector<int>& coded_information, int first, int last){
    int range = last - first + 1;
    int error_index1 = (rand()%range)+first;
    int error_index2 = error_index1;
    while (error_index2 == error_index1){
        error_index2 = (rand()%range)+first;
    }

    if (coded_information[error_index1] == 0){
        coded_information[error_index1] = 1;
    } else {
        coded_information[error_index1] = 0;
    }

    if (coded_information[error_index2] == 0){
        coded_information[error_index2] = 1;
    } else {
        coded_information[error_index2] = 0;
    }

    return coded_information;
}

vector<int> three_errors(vector<int>& coded_information, int first, int last){
    int range = last - first + 1;
    int error_index1 = (rand()%range)+first;
    int error_index2 = error_index1;
    while (error_index2 == error_index1){
        error_index2 = (rand()%range)+first;
    }
    int error_index3 = error_index1;
    while (error_index3 == error_index1 || error_index3 == error_index2){
        error_index3 = (rand()%range)+first;
    }

    if (coded_information[error_index1] == 0){
        coded_information[error_index1] = 1;
    } else {
        coded_information[error_index1] = 0;
    }

    if (coded_information[error_index2] == 0){
        coded_information[error_index2] = 1;
    } else {
        coded_information[error_index2] = 0;
    }

    if (coded_information[error_index3] == 0){
        coded_information[error_index3] = 1;
    } else {
        coded_information[error_index3] = 0;
    }

    return coded_information;
}

vector<int> four_errors(vector<int>& coded_information, int first, int last){
    int range = last - first + 1;
    int error_index1 = (rand()%range)+first;
    int error_index2 = error_index1;
    while (error_index2 == error_index1){
        error_index2 = (rand()%range)+first;
    }
    int error_index3 = error_index1;
    while (error_index3 == error_index1 || error_index3 == error_index2){
        error_index3 = (rand()%range)+first;
    }
    int error_index4 = error_index1;
    while (error_index4 == error_index1 || error_index4 == error_index2 || error_index4 == error_index3){
        error_index4 = (rand()%range)+first;
    }

    if (coded_information[error_index1] == 0){
        coded_information[error_index1] = 1;
    } else {
        coded_information[error_index1] = 0;
    }

    if (coded_information[error_index2] == 0){
        coded_information[error_index2] = 1;
    } else {
        coded_information[error_index2] = 0;
    }

    if (coded_information[error_index3] == 0){
        coded_information[error_index3] = 1;
    } else {
        coded_information[error_index3] = 0;
    }

    if (coded_information[error_index4] == 0){
        coded_information[error_index4] = 1;
    } else {
        coded_information[error_index4] = 0;
    }

    return coded_information;
}

vector<int> two_errors_group(vector<int>& coded_information, int first, int last, int length){
    int range = last - first + 1 - length + 1;
    int error_index1 = (rand()%range)+first;
    int error_index2 = error_index1 + length - 1;

    if (coded_information[error_index1] == 0){
        coded_information[error_index1] = 1;
    } else {
        coded_information[error_index1] = 0;
    }

    if (coded_information[error_index2] == 0){
        coded_information[error_index2] = 1;
    } else {
        coded_information[error_index2] = 0;
    }

    return coded_information;
}

vector<int> three_errors_group(vector<int>& coded_information, int first, int last, int length){
    int range = last - first + 1 - length + 1;
    int error_index1 = (rand()%range)+first;
    int error_index2 = error_index1 + length - 1;
    int inner_range = length - 2;
    int error_index3 = (rand()%inner_range) + error_index1 + 1;

    if (coded_information[error_index1] == 0){
        coded_information[error_index1] = 1;
    } else {
        coded_information[error_index1] = 0;
    }

    if (coded_information[error_index2] == 0){
        coded_information[error_index2] = 1;
    } else {
        coded_information[error_index2] = 0;
    }

    if (coded_information[error_index3] == 0){
        coded_information[error_index3] = 1;
    } else {
        coded_information[error_index3] = 0;
    }

    return coded_information;
}

vector<int> four_errors_group(vector<int>& coded_information, int first, int last, int length){
    int range = last - first + 1 - length + 1;
    int error_index1 = (rand()%range)+first;
    int error_index2 = error_index1 + length - 1;
    int inner_range = length - 2;
    int error_index3 = (rand()%inner_range) + error_index1 + 1;
    int error_index4 = error_index3;
    while (error_index4 == error_index3){
        error_index4 = (rand()%inner_range) + error_index1 + 1;
    }

    if (coded_information[error_index1] == 0){
        coded_information[error_index1] = 1;
    } else {
        coded_information[error_index1] = 0;
    }

    if (coded_information[error_index2] == 0){
        coded_information[error_index2] = 1;
    } else {
        coded_information[error_index2] = 0;
    }

    if (coded_information[error_index3] == 0){
        coded_information[error_index3] = 1;
    } else {
        coded_information[error_index3] = 0;
    }

    if (coded_information[error_index4] == 0){
        coded_information[error_index4] = 1;
    } else {
        coded_information[error_index4] = 0;
    }

    return coded_information;
}

vector<int> polynomialDivison(const vector<int>& divisor, vector<int>& dividend){
    vector<int> quotient, remainder;
    quotient.resize(dividend.size()-divisor.size()+1);
    copy(dividend.begin(), dividend.end(), back_inserter(remainder));
    while(remainder.size()>=divisor.size()) {
        quotient[quotient.size()-(remainder.size()-divisor.size())-1]=1;
        for (int i = 0; i < divisor.size(); i++) remainder[i] = (remainder[i] + divisor[i]) % 2;
        while (remainder[0]==0 && !remainder.empty()) {
        	remainder.erase(remainder.begin());
		}
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
    int i = 0;
    do{
        vector<int> syndrome = polynomialDivison(generator_15_7, coded_information);
        int wage = count(syndrome.begin(), syndrome.end(), 1);

        if(wage <= 2){
            for(int j=1; j<=syndrome.size(); j++){
                coded_information[coded_information.size()-j]=(coded_information[coded_information.size()-j]+syndrome[syndrome.size()-j])%2;
            }
            for(int k=0; k<i; k++){
                rotate(coded_information.rbegin(), coded_information.rbegin() + 1, coded_information.rend());
            }
            vector<int> decoded_information;
            copy(coded_information.begin(),coded_information.begin()+7, back_inserter(decoded_information));
            return decoded_information;
        }
        if(i==7) return error;
        else{
            rotate(coded_information.begin(), coded_information.begin() + 1, coded_information.end());
            i++;
        }
    }while(true);
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
    int i = 0;
    do{
        vector<int> syndrome = polynomialDivison(generator_15_5, coded_information);
        int wage = count(syndrome.begin(), syndrome.end(), 1);

        if(wage <= 3){
            for(int j=1; j<=syndrome.size(); j++){
                coded_information[coded_information.size()-j]=(coded_information[coded_information.size()-j]+syndrome[syndrome.size()-j])%2;
            }
            for(int k=0; k<i; k++){
                rotate(coded_information.rbegin(), coded_information.rbegin() + 1, coded_information.rend());
            }
            vector<int> decoded_information;
            copy(coded_information.begin(),coded_information.begin()+5, back_inserter(decoded_information));
            return decoded_information;
        }
        if(i==5) return error;
        else{
            rotate(coded_information.begin(), coded_information.begin() + 1, coded_information.end());
            i++;
        }
    }while(true);
}
