#include<bits/stdc++.h>

using namespace std;

int analyse_file(map<string, int>& word_c, string filename){
	// filestream variable file 
    fstream file_ptr; 
    
    string word, file_in_disguise; 
    int file_length= 0;
    // filename of the file 
    file_in_disguise = filename; 
  
    // opening file 
    file_ptr.open(file_in_disguise.c_str()); 
  
    // extracting words from the file 
    while (file_ptr >> word){
        file_length++;
        if(word_c.find(word) != word_c.end())
            word_c[word]++;
        else
            word_c[word]= 1;

    }
    return file_length;
}

void print_map(map<string, int>& m){
    cout << "Word\t\tCount\n";
    for(auto it=m.begin(); it!= m.end(); it++)
        cout << (*it).first << "\t\t" << (*it).second << endl;
}

int main(void){

    string file_in_disguise;
    cout << "Filename > ";
    cin >> file_in_disguise;
    cout << file_in_disguise << endl;

	map<string, int> word_c; //To store the count of every word.
	int file_length = analyse_file(word_c, file_in_disguise);
    cout << "File Length > " << file_length << "\n\n";
    print_map(word_c);

	return 0;
}