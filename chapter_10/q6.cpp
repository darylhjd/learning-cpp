#include <iostream>
#include <array>
#include <algorithm>
#include <random>
#include <ctime>

enum class CardRank {
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,
};

enum class CardSuite {
    clubs,
    diamonds,
    hearts,
    spades,
};

struct Card {
    CardRank rank{};
    CardSuite suite{};
};

constexpr int deck_card_count{52};
using card_deck_t = std::array<Card, deck_card_count>;

void print_card(const Card& card) {
    char rank{'?'};
    switch (card.rank) {
    case CardRank::two:
        rank = '2';
        break;
    case CardRank::three:
        rank = '3';
        break;
    case CardRank::four:
        rank = '4';
        break;
    case CardRank::five:
        rank = '5';
        break;
    case CardRank::six:
        rank = '6';
        break;
    case CardRank::seven:
        rank = '7';
        break;
    case CardRank::eight:
        rank = '8';
        break;
    case CardRank::nine:
        rank = '9';
        break;
    case CardRank::ten:
        rank = 'T';
        break;
    case CardRank::jack:
        rank = 'J';
        break;
    case CardRank::queen:
        rank = 'Q';
        break;
    case CardRank::king:
        rank = 'K';
        break;
    case CardRank::ace:
        rank = 'A';
        break;
    }

    char suite{'?'};
    switch (card.suite) {
    case CardSuite::clubs:
        suite = 'C';
        break;
    case CardSuite::diamonds:
        suite = 'D';
        break;
    case CardSuite::hearts:
        suite = 'H';
        break;
    case CardSuite::spades:
        suite = 'S';
        break;
    }

    std::cout << rank << suite;
}

card_deck_t createDeck() {
    card_deck_t cards{};
    int index{0};
    for (int s{static_cast<int>(CardSuite::clubs)}; s <= static_cast<int>(CardSuite::spades); ++s) {
        for (int r{static_cast<int>(CardRank::two)}; r <= static_cast<int>(CardRank::ace); ++r) {
            cards[index].rank = static_cast<CardRank>(r);
            cards[index].suite = static_cast<CardSuite>(s);
            ++index;
        }
    }
    return cards;
}

void print_deck(const card_deck_t& deck) {
    for (auto& card: deck) {
        print_card(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffle_deck(card_deck_t& deck) {
    static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card) {
    if (card.rank == CardRank::ace) {
        return 11;
    } else if (card.rank < CardRank::ten) {
        return static_cast<int>(card.rank) + 2;
    } else {
        return 10;
    }
}

int main() {
    auto deck{createDeck()};

    print_deck(deck);

    print_card(deck[13]);
    std::cout << '\n' << getCardValue(deck[13]) << '\n';

    shuffle_deck(deck);
    print_deck(deck);
}