#pragma once
#include <iostream>

class Item;

 namespace ShopGame {

        class ItemStack {
        public:
            ItemStack(Item* item, std::byte quantity) : item(item), count(quantity) {}

            Item* getItem() const;

            std::byte getCount() const;

            void setCount(int newQuantity);

            void increaseCount(int amount);

            void decreaseCount(int amount);

        private:
            Item* item;   // Pointer to the item type
            std::byte count; // Quantity of this item in the stack

        };

 } // namespace ShopGame

