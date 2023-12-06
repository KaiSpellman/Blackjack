#include <iostream>
#include <vector>
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

}

void shuffleDeck(vector<Card>* deck) {

}

int main() {
    vector<Card>* deck = new vector<Card>;
    createDeck(deck);
    delete deck;

    return 0;
}