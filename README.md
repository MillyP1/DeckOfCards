# DeckOfCards

DISCLAIMER: This is just a self project. I'm creating this as a way to learn Neovim and git.
In the future, I want to make this into a library so that I can implement this into several standalone card game applications.

Creating a Deck object will create an array of cards in order.
The order corresponds to opening a new pack of cards in real life.

A deck can be shuffled and cut.
Shuffling obviously shuffles the deck. Cutting picks a random position in the deck and moves every card from the front of the deck to the back until that position.
For games like blackjack, where the dealer marks the cut card without actually cutting the deck as described above, it just chooses a position.
Setting a cut position is seperate than the cut function. The cut function uses the cut position function.
