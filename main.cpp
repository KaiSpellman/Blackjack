#include <iostream>
#include <vector>
#include <algorithm>
#include "card.cpp"

//Bet $2-$500
//Face cards are worth 10
//Ace worth 1 or 11, you choose
using namespace std;

void createDeck(vector<Card>* deck) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            Card *c = new Card(i, j);
            deck->push_back(*c);
        }
    }
}

void swap(vector<Card>* deck, int idx1, int idx2) {
    Card temp = (*deck).at(idx1);
    (*deck).at(idx1) = (*deck).at(idx2);
    (*deck).at(idx2) = temp;
}

void shuffleDeck(vector<Card>* deck) {
    int n = deck->size();

    for (int i = n-1; i > 0; --i)
    {
        int j = rand() % (i + 1);
        swap(deck,i,j);
    }
}

int main() {
    vector<Card>* deck = new vector<Card>;
    createDeck(deck);
    shuffleDeck(deck);
    for (int i = 0; i < 52; i++)
    {
        cout << deck->at(i).getValue() << " " << deck->at(i).getSuit() << endl;
    }
    
    
    delete deck;

    return 0;
}