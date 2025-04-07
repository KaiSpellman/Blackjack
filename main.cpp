#include <iostream>

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Rank { TWO=2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK=10, QUEEN=10, KING=10, ACE=11 };

struct Card {
    Suit suit;
    Rank rank;
};

class Deck {
public:
    std::vector<Card> cards;

    Deck() {
        for (int s = 0; s < 4; ++s) {
            for (int r = 2; r <= 14; ++r) {
                Rank rank = (r <= 10) ? static_cast<Rank>(r) : static_cast<Rank>(10);
                if (r == 14) rank = ACE;
                cards.push_back({ static_cast<Suit>(s), rank });
            }
        }
    }

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    Card deal() {
        Card c = cards.back();
        cards.pop_back();
        return c;
    }
};

int calculateHandValue(std::vector<Card>& hand) {
    int value = 0, aces = 0;
    for (auto& card : hand) {
        value += card.rank;
        if (card.rank == ACE) aces++;
    }
    while (value > 21 && aces--) {
        value -= 10; // Count ACE as 1 instead of 11
    }
    return value;
}

void playGame() {
    Deck deck;
    deck.shuffle();

    std::vector<Card> playerHand = { deck.deal(), deck.deal() };
    std::vector<Card> dealerHand = { deck.deal(), deck.deal() };

    // Player's turn
    while (true) {
        int value = calculateHandValue(playerHand);
        std::cout << "Your hand value: " << value << "\n";
        if (value > 21) {
            std::cout << "You bust!\n";
            return;
        }

        std::cout << "Hit or Stand? (h/s): ";
        char choice;
        std::cin >> choice;
        if (choice == 's') break;
        playerHand.push_back(deck.deal());
    }

    // Dealer's turn
    while (calculateHandValue(dealerHand) < 17) {
        dealerHand.push_back(deck.deal());
    }

    int playerValue = calculateHandValue(playerHand);
    int dealerValue = calculateHandValue(dealerHand);

    std::cout << "Dealer's hand value: " << dealerValue << "\n";
    if (dealerValue > 21 || playerValue > dealerValue) {
        std::cout << "You win!\n";
    } else if (playerValue == dealerValue) {
        std::cout << "Push.\n";
    } else {
        std::cout << "You lose.\n";
    }
}

int main() {
    char again = 'y';
    while (again == 'y') {
        playGame();
        std::cout << "Play again? (y/n): ";
        std::cin >> again;
    }
    return 0;
}
