//
// Created by Romain on 23/05/2018.
//

#ifndef BUFFERED_SOCKET_HPP
#define BUFFERED_SOCKET_HPP

#include <cassert>
#include <iostream>
#include <vector>
//#include <mipp.h>
#include <aff3ct.hpp>
#include "Circular_Buffer.hpp"

template<typename T>
class Buffered_Socket
{

protected:
aff3ct::module::Socket* socket;
aff3ct::module::Socket_type socket_type;
unsigned int buffer_size;
const std::string type_name;
const std::string     name;
int connection_nbr = 0;

std::vector<T>*     socket_data;
Circular_Buffer<T>* buffer;

public:
Buffered_Socket(aff3ct::module::Socket* socket, aff3ct::module::Socket_type socket_type, int buffer_size);
virtual ~Buffered_Socket();

int pop();
int push();
int bind(Buffered_Socket<T>* s);
void print_socket_data();

inline Circular_Buffer<T>* get_buffer         () const {return this->buffer;          }
inline std::string         get_name           () const { return this->name;           }
inline std::string         get_type_name      () const { return this->type_name;      }
inline int                 get_connection_nbr () const { return this->connection_nbr; }
};

#endif //BUFFERED_SOCKET_HPP
