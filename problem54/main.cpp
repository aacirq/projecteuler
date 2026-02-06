#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <array>
#include <tuple>
#include <algorithm>

enum class CardNumber
{
    N2 = 2,
    N3,
    N4,
    N5,
    N6,
    N7,
    N8,
    N9,
    N10,
    J,
    Q,
    K,
    A
};

static std::unordered_map<char, CardNumber> char_to_card_number {{'2', CardNumber::N2},
                                                                 {'3', CardNumber::N3},
                                                                 {'4', CardNumber::N4},
                                                                 {'5', CardNumber::N5},
                                                                 {'6', CardNumber::N6},
                                                                 {'7', CardNumber::N7},
                                                                 {'8', CardNumber::N8},
                                                                 {'9', CardNumber::N9},
                                                                 {'T', CardNumber::N10},
                                                                 {'J', CardNumber::J},
                                                                 {'Q', CardNumber::Q},
                                                                 {'K', CardNumber::K},
                                                                 {'A', CardNumber::A}};

CardNumber getCardNumber(const char num)
{
    return char_to_card_number.at(num);
}

enum class CardSuit
{
    Spades = 0,
    Hearts,
    Diamonds,
    Clubs
};

static std::unordered_map<char, CardSuit> char_to_card_suit {{'S', CardSuit::Spades},
                                                             {'H', CardSuit::Hearts},
                                                             {'D', CardSuit::Diamonds},
                                                             {'C', CardSuit::Clubs}};

CardSuit getCardSuit(const char suit)
{
    return char_to_card_suit.at(suit);
}

enum class Rank
{
    HighCard = 0,
    OnePair,
    TwoPairs,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    RoyalFlush
};

struct Card
{
    CardNumber number;
    CardSuit suit;
};

Card str2Card(const std::string& str)
{
    return Card {getCardNumber(str[0]), getCardSuit(str[1])};
}

bool sameSuit(const std::array<Card, 5>& cards)
{
    const CardSuit suit = cards[0].suit;
    return std::all_of(cards.begin(), cards.end(), [suit](const Card& card) {
        return card.suit == suit;
    });
}

std::tuple<Rank, std::vector<CardNumber>, std::vector<Card>>
rankFiveCards(std::array<Card, 5> cards)
{
    std::sort(cards.begin(), cards.end(), [](const Card& lhs, const Card& rhs) {
        if (lhs.number == rhs.number) {
            return lhs.suit < rhs.suit;
        }
        return lhs.number < rhs.number;
    });

    const bool same_suit = sameSuit(cards);
    bool is_straight = true;
    for (size_t i = 1; i < cards.size(); ++i) {
        if (static_cast<int>(cards[i].number) != static_cast<int>(cards[i - 1].number) + 1) {
            is_straight = false;
            break;
        }
    }

    // check royal flush
    if (same_suit) {
        if (cards[0].number == CardNumber::N10 && cards[1].number == CardNumber::J
            && cards[2].number == CardNumber::Q && cards[3].number == CardNumber::K
            && cards[4].number == CardNumber::A) {
            return {Rank::RoyalFlush, {CardNumber::A}, {}};
        }
    }

    // check straight flush
    if (same_suit) {
        if (is_straight) {
            return {Rank::StraightFlush, {cards[4].number}, {}};
        }
    }

    // check four of a kind
    if (CardNumber number = cards[1].number;
        cards[1].number == number && cards[2].number == number && cards[3].number == number) {
        if (cards[0].number == number) {
            return {Rank::FourOfAKind, {number}, {cards[4]}};
        }
        if (cards[4].number == number) {
            return {Rank::FourOfAKind, {number}, {cards[0]}};
        }
    }

    // check full house
    if (cards[0].number == cards[1].number && cards[1].number == cards[2].number
        && cards[3].number == cards[4].number) {
        return {Rank::FullHouse, {cards[0].number, cards[3].number}, {}};
    }
    if (cards[0].number == cards[1].number && cards[2].number == cards[3].number
        && cards[3].number == cards[4].number) {
        return {Rank::FullHouse, {cards[2].number, cards[0].number}, {}};
    }

    // check flush
    if (same_suit) {
        return {Rank::Flush, {cards[4].number}, std::vector(cards.begin(), cards.begin() + 4)};
    }

    // check straight
    if (is_straight) {
        return {Rank::Straight, {cards[4].number}, std::vector(cards.begin(), cards.begin() + 4)};
    }

    // check three of a kind
    if (cards[0].number == cards[1].number && cards[1].number == cards[2].number) {
        return {Rank::ThreeOfAKind, {cards[0].number}, {cards[3], cards[4]}};
    }
    if (cards[1].number == cards[2].number && cards[2].number == cards[3].number) {
        return {Rank::ThreeOfAKind, {cards[1].number}, {cards[0], cards[4]}};
    }
    if (cards[2].number == cards[3].number && cards[3].number == cards[4].number) {
        return {Rank::ThreeOfAKind, {cards[2].number}, {cards[0], cards[1]}};
    }

    // check two pairs
    if (cards[0].number == cards[1].number && cards[2].number == cards[3].number) {
        return {Rank::TwoPairs, {cards[2].number, cards[0].number}, {cards[4]}};
    }
    if (cards[0].number == cards[1].number && cards[3].number == cards[4].number) {
        return {Rank::TwoPairs, {cards[3].number, cards[0].number}, {cards[2]}};
    }
    if (cards[1].number == cards[2].number && cards[3].number == cards[4].number) {
        return {Rank::TwoPairs, {cards[3].number, cards[1].number}, {cards[0]}};
    }

    // check one pair
    if (cards[0].number == cards[1].number) {
        return {Rank::OnePair, {cards[0].number}, {cards[2], cards[3], cards[4]}};
    }
    if (cards[1].number == cards[2].number) {
        return {Rank::OnePair, {cards[1].number}, {cards[0], cards[3], cards[4]}};
    }
    if (cards[2].number == cards[3].number) {
        return {Rank::OnePair, {cards[2].number}, {cards[0], cards[1], cards[4]}};
    }
    if (cards[3].number == cards[4].number) {
        return {Rank::OnePair, {cards[3].number}, {cards[0], cards[1], cards[2]}};
    }

    // high card
    return {Rank::HighCard, {cards[4].number}, {cards[0], cards[1], cards[2], cards[3]}};
}

int compareFiveCards(const std::array<Card, 5>& cards_player1,
                     const std::array<Card, 5>& cards_player2)
{
    auto [rank_player1, rank_numbers_player1, left_cards_player1] = rankFiveCards(cards_player1);
    auto [rank_player2, rank_numbers_player2, left_cards_player2] = rankFiveCards(cards_player2);

    if (rank_player1 != rank_player2) {
        return rank_player1 > rank_player2 ? 1 : -1;
    }

    if (rank_numbers_player1.size() != rank_numbers_player2.size()) {
        std::cout << "Error: rank numbers size mismatch" << std::endl;
        return 0;
    }

    for (size_t i = 0; i < rank_numbers_player1.size(); ++i) {
        if (rank_numbers_player1[i] != rank_numbers_player2[i]) {
            return rank_numbers_player1[i] > rank_numbers_player2[i] ? 1 : -1;
        }
    }

    if (left_cards_player1.size() != left_cards_player2.size()) {
        std::cout << "Error: left cards size mismatch" << std::endl;
        return 0;
    }

    for (auto it1 = left_cards_player1.rbegin(), it2 = left_cards_player2.rbegin();
         it1 != left_cards_player1.rend();
         ++it1, ++it2) {
        if (it1->number != it2->number) {
            return it1->number > it2->number ? 1 : -1;
        }
    }

    std::cout << "Error: tie" << std::endl;

    return 0;
}

int main()
{
    std::string file_path = "../../problem54/0054_poker.txt";

    std::ifstream fstm(file_path, std::ios::in);
    std::string card;
    constexpr size_t HAND_COUNT = 1000;

    size_t result = 0;

    for (size_t i = 0; i < HAND_COUNT; i++) {
        constexpr size_t CARD_COUNT_PER_PLAYER = 5;
        std::array<Card, CARD_COUNT_PER_PLAYER> cards_player1 {};
        std::array<Card, CARD_COUNT_PER_PLAYER> cards_player2 {};
        for (size_t j = 0; j < CARD_COUNT_PER_PLAYER; j++) {
            fstm >> card;
            cards_player1[j] = str2Card(card);
        }
        for (size_t j = 0; j < CARD_COUNT_PER_PLAYER; j++) {
            fstm >> card;
            cards_player2[j] = str2Card(card);
        }

        if (compareFiveCards(cards_player1, cards_player2) > 0) {
            ++result;
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
