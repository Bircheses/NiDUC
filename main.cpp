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
vector<int> two_errors_group(vector<int>& coded_information, int first, int last);      // last - ostatni indeks, od ktorego mozna zaczac grupe bledow
vector<int> three_errors_group(vector<int>& coded_information, int first, int last);
vector<int> four_errors_group(vector<int>& coded_information, int first, int last);
bool compare_vectors(vector<int>& input, vector<int>& output);


int main() {
    srand(time(NULL));
    float test_number = 500;
    float correct_decode = 0;

    for (int i = 0; i < test_number; i++){
        cout << "KOD (15,7)\n";
        vector<int> information1 = {1,0,0,0,0,0,0};
        for (int j = 1; j < 7; j++){
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
        //coded_information1 = two_errors_group(coded_information1, 1, 5);      // grupa 2 bledow, cz. inf.
        //coded_information1 = two_errors_group(coded_information1, 7, 13);      // grupa 2 bledow, cz. kontr.
        //coded_information1 = three_errors_group(coded_information1, 1, 4);      // grupa 3 bledow, cz. inf.
        //coded_information1 = three_errors_group(coded_information1, 7, 12);      // grupa 3 bledow, cz. kontr.
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
/*
    for (int i = 0; i < test_number; i++){
        cout << "KOD (15,5)\n";
        vector<int> information2 = {1,0,0,0,0};
        for (int j = 1; j < 5; j++){
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
        //coded_information2 = two_errors_group(coded_information2, 1, 3);      // grupa 2 bledow, cz. inf.
        //coded_information2 = two_errors_group(coded_information2, 5, 13);      // grupa 2 bledow, cz. kontr.
        //coded_information2 = three_errors_group(coded_information2, 1, 2);      // grupa 3 bledow, cz. inf.
        //coded_information2 = three_errors_group(coded_information2, 5, 12);      // grupa 3 bledow, cz. kontr.
        //coded_information2 = four_errors_group(coded_information2, 1, 1);      // grupa 4 bledow, cz. inf.
        //coded_information2 = four_errors_group(coded_information2, 5, 11);      // grupa 4 bledow, cz. kontr.

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



    /*
    cout << "KOD (15,7)\n";
    vector<int> information2 = {1,0,1,1,0};
    cout << "wektor wejsciowy: ";
    showVector(information2);
    vector<int> coded_information1 = coder_15_7(information1);
    cout << "zakodowany: ";
    showVector(coded_information1);
    //coded_information1[1] = 1;
    //coded_information1[2] = 0;
    //coded_information1[3] = 0;
    //coded_information1[11] = 0;
    coded_information1[12] = 0;
    coded_information1[13] = 1;
    //coded_information1[14] = 1;
    cout << "z bledami:  ";
    showVector(coded_information1);
    vector<int> decoded_information1 = decoder_15_7(coded_information1);
    cout << "dekodowany: ";
    showVector(decoded_information1);

    cout << "\n";

    cout << "KOD (15,5)\n";
    vector<int> information2 = {1,0,1,1,0};
    cout << "wektor wejsciowy: ";
    showVector(information2);
    vector<int> coded_information2 = coder_15_5(information2);
    cout << "zakodowany: ";
    showVector(coded_information2);
    coded_information2[1] = 1;
    coded_information2[2] = 0;
    coded_information2[10] = 1;
    coded_information2[13] = 0;
    cout << "z bledami:  ";
    showVector(coded_information2);
    vector<int> decoded_information2 = decoder_15_5(coded_information2);
    cout << "dekodowany: ";
    showVector(decoded_information2);
    */

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

vector<int> two_errors_group(vector<int>& coded_information, int first, int last){
    int range = last - first + 1;
    int error_index = (rand()%range)+first;

    if (coded_information[error_index] == 0){
        coded_information[error_index] = 1;
    } else {
        coded_information[error_index] = 0;
    }

    if (coded_information[error_index+1] == 0){
        coded_information[error_index+1] = 1;
    } else {
        coded_information[error_index+1] = 0;
    }

    return coded_information;
}

vector<int> three_errors_group(vector<int>& coded_information, int first, int last){
    int range = last - first + 1;
    int error_index = (rand()%range)+first;

    if (coded_information[error_index] == 0){
        coded_information[error_index] = 1;
    } else {
        coded_information[error_index] = 0;
    }

    if (coded_information[error_index+1] == 0){
        coded_information[error_index+1] = 1;
    } else {
        coded_information[error_index+1] = 0;
    }

    if (coded_information[error_index+2] == 0){
        coded_information[error_index+2] = 1;
    } else {
        coded_information[error_index+2] = 0;
    }

    return coded_information;
}

vector<int> four_errors_group(vector<int>& coded_information, int first, int last){
    int range = last - first + 1;
    int error_index = (rand()%range)+first;

    if (coded_information[error_index] == 0){
        coded_information[error_index] = 1;
    } else {
        coded_information[error_index] = 0;
    }

    if (coded_information[error_index+1] == 0){
        coded_information[error_index+1] = 1;
    } else {
        coded_information[error_index+1] = 0;
    }

    if (coded_information[error_index+2] == 0){
        coded_information[error_index+2] = 1;
    } else {
        coded_information[error_index+2] = 0;
    }

    if (coded_information[error_index+3] == 0){
        coded_information[error_index+3] = 1;
    } else {
        coded_information[error_index+3] = 0;
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

        if(wage <= 2){
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
        if(i==7) return error;
        else{
            rotate(coded_information.begin(), coded_information.begin() + 1, coded_information.end());
            i++;
        }
    }while(true);
}
