#include <iostream>

/// creating a program that reads data into vectors
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <vector>

using namespace std;
int readSATscores(vector <int> &, vector <int> &, vector <int> &, vector <int> &);
void printArray(const vector <int> &);
int sumscores (vector <int> &, vector <int> &, vector <int> & ,vector <int> &);
int findmax(vector <int> &);
int tallyarea(vector <int> &, int);

ofstream outfile(" Vector Score Sheet.txt");

int main()
{
    vector <int> idnum, readingscores,mathscores, writingscores;
    vector <int> totalscores;
    int index, threshold=650;
    int n, numthresh;
// calling the scores
    n=readSATscores(idnum,readingscores,mathscores,writingscores);
    cout << "There were: " << n << " students in attendance for the exam."<< endl;
    cout<< endl;
//printing the values in the array to the data file
      outfile<< setw(45)<<"Snapshot of data taken from 2015 SAT."<<endl;
      outfile<< setw(42)<<"________________________________"<<endl;
      outfile << "ID numbers of students present for the test. "<< endl;
         printArray(idnum);
      outfile << "The reading scores collected are."<<endl;
         printArray(readingscores);
      outfile << "The math scores collected are."<<endl;
         printArray(mathscores);
      outfile << "The writing scores collected are."<<endl;
         printArray(writingscores);
//calling the sum of three arrays into new array totalscores.
       sumscores(readingscores,mathscores,writingscores,totalscores);
//printing totalscores array
       outfile<< "The cumulated SAT scores are:"<<endl;
    printArray(totalscores);
       outfile<<endl;
//calling the function to find the max score of the cumulated test
      outfile<< setw(45)<<"2015 SAT statistics."<<endl;
      outfile<< setw(47)<<"____________________________"<<endl;
    index=findmax(totalscores);
       outfile << "The student with the highest score is: "<< idnum[index]<< endl;
//calling the function that determines the amount of students above threshold
    numthresh=tallyarea(writingscores,threshold);
       outfile<< "The amount of students above the threshold in writing is: "<< numthresh <<endl;

    outfile.close();

    return 0;
}
/**
Input: integer vectors idnum, readingscores, mathscores and writingscores containing n elements
Process: read in from from data file n elements into idnum, readingscores, mathscores and writingscores
Output: idnum, readingscores, mathscores and writingscores are filled with n values.
**/
int readSATscores(vector <int> & id,vector <int> & readscore, vector <int> & mathscore, vector <int> & writescore)
{
//opening read in data file
    fstream myinfile;
    myinfile.open("student info.txt");
    if (!myinfile) {
        cout << "file student info.txt does not exist! Program will exit.";
        exit(1);
    }
//reading data file to vectors with while loop
    int idnum, reading,math,writing;
    int student=0;
    myinfile >> idnum>> reading >> math >> writing;
    while (!myinfile.eof()){
        id.push_back(idnum);
        readscore.push_back(reading);
        mathscore.push_back(math);
        writescore.push_back(writing);
    myinfile >> idnum>> reading >> math >> writing;
       student++;
    }
//printing the arrays to the screen
  for ( unsigned int i=0; i<mathscore.size(); i++){
   cout << "Student: " << id.at(i)<< " Received: "<< readscore.at(i) << " in reading " << mathscore.at(i) << " in math and " << writescore.at(i) << " in writing."<< endl;
   outfile << "Student: " << id.at(i)<< " Received: "<< readscore.at(i) << " in reading " << mathscore.at(i) << " in math and " << writescore.at(i) << " in writing."<< endl;
}

     myinfile.close();
    return id.size();
}
/**
Input: integer vector arr receives the values from other arrays
Process: the for loop reads the numbers in the vector
Output: the numbers in the four integer vectors are printed to file
**/
void printArray(const vector <int> & arr)
{
    for (unsigned int i=0; i< arr.size(); i++)
        outfile <<  arr[i] << ' ';
        outfile <<endl;
}
/**
Input: values from the three integer vectors reading,math,writing containing the test scores
Process:the loop adds the values that are in the same index position together
Output: the sum of the values are placed in the new integer vector totalscores
**/
int sumscores(vector <int> & reading, vector <int> & math, vector <int> & writing, vector <int> & totalscores)
{
    int ScoreSum;
   for (unsigned int i=0; i<reading.size(); i++){
    ScoreSum=reading.at(i)+math.at(i)+writing.at(i);
    totalscores.push_back(ScoreSum);
   }
   return 0;
}
/**Input:vector arr receives values from the other vectors with scores
Process:goes through the vector evaluating the numbers
Output: prints out the maximum grade on exam part
**/
int findmax (vector <int> & arr)
{

    int maxgrade=arr[0];
    for (unsigned int i=0; i<arr.size(); i++){
    if (arr[i]> maxgrade)
        maxgrade=arr[i];
    }
    for (unsigned int i=0;i<arr.size();i++){
        if (arr[i]==maxgrade)
            return i;
    }
    return -1;
}
/**
Input: vector arr receives values from the test score vectors
Process:the values are compared to a set threshold number
Output: the amount of test scores in arrays that are above the threshold
**/
int tallyarea(vector <int> & arr, int threshold)
{
    int numstud=0;
    for(unsigned int i=0; i<arr.size(); i++){
        if (arr[i]>=threshold)
            numstud++;
    }
    return numstud;
}
