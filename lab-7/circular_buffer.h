#include <iostream>


#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H


void exit_index_out_of_range() {
    std::cerr << "Index out of range";
    exit(-1);
}

void exit_segmentation_fault() {
    std::cerr << "Segmentation fault";
    exit(-1);
}

template<typename Type>
class circular_buffer {
private:
    size_t start, finish, size, capacity;
    Type* data;

    size_t to_next_nearest_degree (size_t value) {
        if (value <= 0)
            return 0;

        --value;
        value |= value >> 1;
        value |= value >> 2;
        value |= value >> 4;
        value |= value >> 8;
        value |= value >> 16;

        return value + 1;
    }


public:

    circular_buffer(circular_buffer <Type> &other) {
        start = other.start;
        finish = other.finish;
        size = other.size;
        capacity = other.capacity;
        data = new Type[capacity];

        for (size_t i = start; i != finish; i = ++i % size)
            data[i] = other.data[i];
    }

    explicit circular_buffer(size_t size_in = 0, Type value = 0) {
        start = 0;
        finish = 0;
        size = size_in;
        capacity = to_next_nearest_degree(size_in);
        data = new Type[capacity]{};

        if (value)
            for (size_t i = 0; i < size; ++i)
                data[i] = value;
    }

    ~circular_buffer() {
        delete [] data;
    }

    circular_buffer <Type> & operator = (const circular_buffer <Type> &other) {
        if (other == this)
            return *this;

        start = other.start;
        finish = other.finish;
        size = other.size;

        if (capacity < other.capacity) {
            capacity = other.capacity;

            delete[] data;
            data = new Type[capacity];
        }

        for (size_t i = start; i != finish; i = (i + 1) % size)
            data[i] = other.data[i];
    }

    Type& operator [] (size_t index) {
        index += start;
        if (start < finish) {
            if (index < finish)
                return data[index];
            else
                exit_index_out_of_range();
        }

        if (index <= finish + size)
            return data[index % size];
        else
            exit_index_out_of_range();
    }

    Type operator [] (size_t index) const {
        index += start;
        if (start < finish) {
            if (index <= finish)
                return data[index];
            else
                exit_index_out_of_range();
        }

        if (index <= finish + size)
            return data[index % size];
        else
            exit_index_out_of_range();
    }

    void resize(size_t new_size) {
        size = new_size;
        if (new_size <= capacity)
            return;

        capacity = to_next_nearest_degree(new_size);
        Type* temp_data = new Type[capacity];

        for (size_t i = 0; i < size; ++i)
            temp_data = data[i];

        delete [] data;
        data = temp_data;
    }

    void append(Type value) {
        static int count = 0;
        if (!size)
            exit_segmentation_fault();

        if (finish == start && count++)
            start = ++start % size;

        data[finish] = value;
        finish = ++finish % size;
    }

    void append_to_start(Type value) {
        if (!size)
            exit_segmentation_fault();

        start = (start + size - 1) % size;
        data[start] = value;

        if (finish == start)
            finish = (finish + size - 1) % size;
    }

    Type pop() {
        size_t temp = finish;
        finish = (finish + size - 1) % size;
        return data[temp];
    }

    Type pop_from_start() {
        size_t temp = start;
        start = ++start % size;
        return data[temp];
    }



    class iterator {

        using iterator_category = std::random_access_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Type;
        using pointer           = Type*;
        using reference         = Type&;

    private:
        size_t index, start, end, size;
        pointer data;
        bool circle;

        size_t correct_arithmetic(size_t value) {
            value -= start;
            size_t circle_size;

            if (start < end)
                circle_size = end - start + 1;
            else
                circle_size = end + size - start + 1;

            return (start + value) % circle_size;
        }

        size_t distance_to_the_start() const {
            if (index >= start)
                return index - start;
            return size + index - start;
        }

    public:

        iterator(size_t s_index, size_t s_start, size_t s_end, size_t s_size, pointer s_data, bool s_circle):
                index(s_index), start(s_start), end(s_end), size(s_size), data(s_data), circle(s_circle) {}

        reference operator * () const {
            return data[index];
        }

        pointer operator -> () {
            return data + index;
        }

        reference operator [] (size_t value) {
            return *(*this + value);
        }
        //arithmetic operators

        iterator& operator += (difference_type value) {
            index = correct_arithmetic(index + value);
            return *this;
        }

        iterator& operator -= (difference_type value) {
            index = correct_arithmetic(size + index - value);
            return *this;
        }

        iterator operator + (difference_type value) {
            iterator temp(*this);
            temp += value;
            return temp;
        }

        iterator operator - (difference_type value) {
            iterator temp(*this);
            temp -= value;
            return temp;
        }

        iterator& operator++() {
            if (++index == size) {
                index = 0;
                circle = true;
            }

            return *this;
        }


        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        iterator& operator--() {
            if (--index == -1) {
                index = size - 1;
                circle = false;
            }
            return *this;
        }

        iterator operator--(int) {
            iterator temp = *this;
            --(*this);
            return temp;
        }

        //bool operators

        friend bool operator == (const iterator& first, const iterator& second) {
            return first.index == second.index && first.circle == second.circle;
        }

        friend bool operator != (const iterator& first, const iterator& second) {
            /*static size_t count = 0;
            if (first.index != second.index || (first.index == second.index && count++ % 2 == 0))
                return true;*/
            return first.index != second.index || first.circle != second.circle;
        }

        friend bool operator > (const iterator& first, const iterator& second) {
            return first.distance_to_the_start() > second.distance_to_the_start();
        }

        friend bool operator < (const iterator& first, const iterator& second) {
            return first.distance_to_the_start() < second.distance_to_the_start();
        }

        friend bool operator >= (const iterator& first, const iterator& second) {
            return (first.distance_to_the_start() > second.distance_to_the_start()) || first == second;
        }

        friend bool operator <= (iterator first, const iterator& second) {
            return (first.distance_to_the_start() < second.distance_to_the_start()) || first == second;
        }
    };

    iterator begin() {
        return iterator(start, start, finish, size, data, false);
    }

    iterator end() {
        return iterator(finish, start, finish, size, data, true);
    }

};

#endif
