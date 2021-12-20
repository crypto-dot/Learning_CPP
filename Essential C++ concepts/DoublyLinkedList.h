//
// Created by Carlos Arbizu on 12/6/21.
//

#ifndef CPP_DOUBLYLINKEDLIST_H
#define CPP_DOUBLYLINKEDLIST_H
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <initializer_list>
#include <stdexcept>
namespace dsa {
    template <class T>
    class DoubleLinkedList;

    template <class T>
    class DoubleLinkedList {
    public:
        template<class U>
        class Node {
        private:
            T data_;
            Node<T> *prev_, *next_;
            friend class DoubleLinkedList<T>;
        public:
            Node() : prev_{nullptr}, next_{nullptr} {}

            Node(const T &data, Node<T> *prev, Node<T> *next) : data_{data}, prev_{prev}, next_{next} {};

            std::string toString() const{
                std::stringstream os;
                os << "NODE (" << data_ << ")";
                return os.str();
            }
            friend std::ostream &operator<<(std::ostream &ostream1, const Node<T> &node){
                return ostream1 << node.toString();
            }

        };

    private:
        size_t size_= 0;
        Node<T> *head_;
        Node<T> *tail_;
    public:
        DoubleLinkedList() : size_{0},head_{nullptr},tail_{nullptr}{}

        virtual ~DoubleLinkedList() {
            clear();
        }
        class Iterator{
        public:
            Iterator() noexcept : curreNode_{head_} {}
            Iterator(const Node<T>* pNode) noexcept: curreNode_{pNode} {}
            Iterator &operator=(Node<T> *pNode){
                curreNode_ = pNode;
                return *this;
            }
            Iterator &operator++() {
                if(curreNode_){
                    curreNode_ = curreNode_->next_;
                }
                return *this;
            }
            Iterator operator++(int i){
                Iterator iterator = *this;
                ++(*this);
                return iterator;
            }
            bool operator !=(const Iterator &iterator){
                return curreNode_ != iterator.curreNode_;
            }
            T operator*(){
                return curreNode_->data_;
            }
        private:
            const Node<T> *curreNode_;
        };

        void clear() {
            Node<T> *trav = head_;
            while(trav){
                Node<T> *next = trav->next_;
                delete trav;
                trav = nullptr;
                trav = next;
            }
            size_ = 0;
            head_ = nullptr;
            tail_ = nullptr;
        }
        size_t size(){
            return size_;
        }
        bool isEmpty(){
            return size_ == 0;
        }
        void addLast(const T &element){
            if(isEmpty()){
                head_ = new Node<T>(element, nullptr, nullptr);
                tail_ = head_;
            }
            else {
                tail_ = new Node<T>(element,tail_, nullptr);
                tail_ = tail_->next_;
            }
            size_++;
        }
        void addFirst(const T &element){
            if(isEmpty()){
                head_ = new Node<T>(element, nullptr, nullptr);
                tail_ = head_;
            }
            else {
                head_ = new Node<T>(element, nullptr,head_);
                head_ = head_->prev_;
            }
            size_++;
        }
        void addAt(size_t index,const T &element) {
            if (index < 0 || index > size_) {
                throw std::out_of_range("Out of range");
            }
            if (index == size_) {
                addLast(element);
                return;
            }
            if (index == 0) {
                addFirst(element);
                return;
            }
            Node<T> *trav = head_;
            for (size_t i{0}; i < index; i++) {
                trav = trav->next_;
            }
            element = new Node<T>(element, trav, trav->next_);
            trav->next_->prev_ = element;
            trav->next_ = element;
            size_++;
        }
            template <typename T>
            T removeFirst() {
                T data = head_->data;
                head_ = head_->next_;
                --size_;

                if(isEmpty()){
                    delete tail_;
                    tail_ = nullptr;
                }
                else
                {
                    delete head_->prev_;
                    head_->prev_ = nullptr;
                }
                return data;
        }
            template <typename T>
            T removeLast(){
            T data = tail_->data_;
            tail_ = tail_->prev_;

        }
    }
        };
#endif //CPP_DOUBLYLINKEDLIST_H
