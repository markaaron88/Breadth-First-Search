/*
Title: Breadth-First-Search
Abstract: Write a C++ program called BFS.cpp that implements the Breadth-First Search (BFS) algorithm. Your program should read an input file name and a starting node from a user. 
After that, your program should display the list of vertices visited. 
In the problem, you can assume that the number of vertices in the input file is less than or equal to 25. When you write the program, don’t forget to include 
Author: Mark Mariscal
ID: 7198
Date: 02/01/2020
*/



#include<iostream>
#include <fstream>
using namespace std;
void insertInQueue(int queue[], int &length, int vertex)
{

    for(int i = 0; i < length; i++)
    {
        if(queue[i] == vertex)
            return;
    }
    queue[length] = vertex;
    length++;

}
int main()

{
    string fileName;
    int beginning;
    cout << "Enter input file name: "; //asks input
    cin >> fileName;
    cout << "Enter the beginning vertex: ";
    cin >> beginning;
    ifstream infile(fileName);
    int N;
    infile >> N; 

    int adjacency[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            infile >> adjacency[i][j];
    }

    infile.close();


    int queue[N];
    int queue_length = 0;
    queue[0] = beginning;
    queue_length++;
    int vertex;
    for(int i = 0; i < queue_length; i++)
    {
        vertex = queue[i];
        for(int j = 0; j < N; j++)
        {
            if(adjacency[vertex][j] != 0)
                insertInQueue(queue, queue_length, j);
        }
    }
    cout << "\nThe BFS traversal is " << endl;
    cout << queue[0] ;
    for( int i = 1; i < queue_length; i++)
        cout << " ---> " << queue[i] ;
    cout << endl;
}