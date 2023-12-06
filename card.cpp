class Card {
    private:
        int suit; //0-3, spades, hearts, diamonds, clubs
        int value; //0-12
    public:
        void setSuit(int a) {
            this->suit = a;
        }
        void setValue(int a) {
            this->value = a;
        }

        int getSuit() {
            return this->suit;
        }
        int getValue() {
            return this->value;
        }

    Card(int suit, int value) {
        setSuit(suit);
        setValue(value);
    }
};