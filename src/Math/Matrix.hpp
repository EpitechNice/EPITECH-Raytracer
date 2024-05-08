/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Matrix                                                                           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_MATRIX_HPP
    #define INCLUDED_MATRIX_HPP

    #include "headers.hpp"
    #include "../Exceptions/Exceptions.hpp"

namespace Math
{
    template <typename T>
    class Matrix
    {
        protected:
            std::vector<std::vector<T>> _values;
            std::string getClassName() const
            {
                int status = -4;
                const char* name = typeid(*this).name();
                char* _out = abi::__cxa_demangle(name, NULL, NULL, &status);
                if (status != 0 && _out)
                    free(_out);
                if (status != 0)
                    return std::string(name);
                std::string out(_out);
                free(_out);
                return out;
            }

        public:
            Matrix():
                _values({})
            {}

            Matrix(const Matrix<T>& other):
                _values(other._values)
            {}

            Matrix(const std::vector<std::vector<T>>& values):
                _values(values)
            {}

            Matrix(const std::vector<T>& values):
                _values({values})
            {}

            Matrix(std::pair<std::size_t, std::size_t> size, T value):
                _values({})
            {
                this->fill(size, value);
            }

            void set(std::pair<std::size_t, std::size_t> position, T value)
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                if (position.first >= size.first ||
                    position.second >= size.second)
                    throw Exceptions::InvalidPositionError("Trying to set at position (" +
                                                           std::to_string(position.first) +
                                                           ", " +
                                                           std::to_string(position.second) +
                                                           ") that is not in the matrix, which is of size (" +
                                                           std::to_string(size.first) +
                                                           ", " +
                                                           std::to_string(size.second) +
                                                           ")",
                        EXCEPTION_INFOS);
                this->_values[position.first][position.second] = value;
            }

            std::string str() const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                std::stringstream ss;

                ss << "<" << this->getClassName() << " at " <<
                        std::hex << this <<
                        ": size=(" <<
                        size.first << ", " << size.second <<
                        "), values={";
                if (!size.first || !size.second) {
                    ss << "}>";
                    return ss.str();
                }
                if (size.first == 1) {
                    ss << this->_values[0][0];
                    for (std::size_t i = 1; i < size.second; i++) {
                        ss << ", " << this->_values[0][i];
                    }
                    ss << "}>";
                    return ss.str();
                }
                for (std::size_t i = 0; i < size.first; i++) {
                    ss << std::endl << "\t";
                    ss << "{";
                    if (size.second)
                        ss << this->_values[i][0];
                    for (std::size_t j = 1; j < size.second; j++)
                        ss << ", " << this->_values[i][j];
                    ss << "},";
                }
                ss << std::endl << "}>";
                return ss.str();
            }

            std::pair<std::size_t, std::size_t> getSize() const
            {
                if (!this->_values.size())
                    return {0, 0};
                return {this->_values.size(), this->_values[0].size()};
            }

            void fill(std::pair<std::size_t, std::size_t> size, T value)
            {
                this->_values.clear();
                for (std::size_t i = 0; i < size.first; i++) {
                    this->_values.push_back({});
                    for (std::size_t j = 0; j < size.second; j++)
                        this->_values[i].push_back(value);
                }
            }

            const std::vector<T>& operator[](int index) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                if ((std::size_t)(abs(index)) >= size.first)
                    throw Exceptions::InvalidPositionError("Matrix is of size " +
                                                           std::to_string(size.first) +
                                                           " but you asked for index " +
                                                           std::to_string(index), EXCEPTION_INFOS);
                if (index < 0)
                    index += (int)size.first;
                return this->_values[index];
            }

            Matrix<T>& operator=(const Matrix<T>& other)
            {
                this->_values = other._values;
                return *this;
            }

            Matrix<T> operator-() const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                Matrix<T> obj = this;

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        obj._values[i][j] = -obj._values[i][j];
                return obj;
            }

            Matrix<T> operator+ (const Matrix<T>& other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                Matrix<T> obj = this;

                if (other.getSize() != size)
                    throw Exceptions::MatrixSizeError("Trying to add matrix of size " +
                                                      other.getSize() +
                                                      " with matrix of size " +
                                                      size,
                        EXCEPTION_INFOS);
                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        obj._values[i][j] += other._values[i][j];
                return obj;
            }

            Matrix<T>& operator+= (const Matrix<T>& other)
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                if (other.getSize() != size)
                    throw Exceptions::MatrixSizeError("Trying to add matrix of size (" +
                                                      std::to_string(other.getSize().first) + ", " + std::to_string(other.getSize().second) +
                                                      ") with matrix of size (" +
                                                      std::to_string(size.first) + ", " + std::to_string(size.second) + ")",
                        EXCEPTION_INFOS);
                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        this->_values[i][j] += other._values[i][j];
                return *this;
            }

            Matrix<T> operator+ (T other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                Matrix<T> obj = this;

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        obj._values[i][j] += other;
                return obj;
            }

            Matrix<T>& operator+= (T other)
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        this->_values[i][j] += other;
                return *this;
            }

            Matrix<T> operator- (const Matrix<T>& other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                Matrix<T> obj = this;

                if (other.getSize() != size)
                    throw Exceptions::MatrixSizeError("Trying to substract matrix of size (" +
                                                      std::to_string(other.getSize().first) + ", " + std::to_string(other.getSize().second) +
                                                      ") with matrix of size (" +
                                                      std::to_string(size.first) + ", " + std::to_string(size.second) + ")",
                        EXCEPTION_INFOS);
                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        obj._values[i][j] -= other._values[i][j];
                return obj;
            }

            Matrix<T>& operator-= (const Matrix<T>& other)
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                if (other.getSize() != size)
                    throw Exceptions::MatrixSizeError("Trying to substract matrix of size (" +
                                                      std::to_string(other.getSize().first) + ", " + std::to_string(other.getSize().second) +
                                                      ") with matrix of size (" +
                                                      std::to_string(size.first) + ", " + std::to_string(size.second) + ")",
                        EXCEPTION_INFOS);
                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        this->_values[i][j] -= other._values[i][j];
                return *this;
            }

            Matrix<T> operator- (T other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                Matrix<T> obj = this;

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        obj._values[i][j] -= other;
                return obj;
            }

            Matrix<T>& operator-= (T other)
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        this->_values[i][j] -= other;
                return *this;
            }

            Matrix<T> operator* (const Matrix<T>& other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                if (size.second != other.getSize().first)
                    throw Exceptions::InvalidSizeError("Trying to multiply matrix of size " +
                                                       other.getSize() +
                                                       " with matrix of size " +
                                                       size,
                        EXCEPTION_INFOS);
                if (!size.first || !size.second)
                    return Matrix<T>();

                Matrix<T> out({size.second, other.getSize().first}, this->_values[0][0]);

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < other.getSize().second; j++)
                        for (std::size_t k = 0; k < size.second; k++)
                            out.set({i, j}) += this->_values[i][k] * other._values[k][j];
                return out;
            }

            Matrix<T> operator* (T other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                Matrix<T> obj = this;

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        obj._values[i][j] *= other;
                return obj;
            }

            Matrix<T>& operator*= (T other)
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        this->_values[i][j] *= other;
                return *this;
            }

            Matrix<T> operator/ (T other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();
                Matrix<T> obj = this;

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        obj._values[i][j] /= other;
                return obj;
            }

            Matrix<T>& operator/= (T other)
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        this->_values[i][j] /= other;
                return *this;
            }

            bool operator== (const Matrix<T>& other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                if (size != other.getSize())
                    return false;
                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.first; j++)
                        if (this->_values[i][j] != other._values[i][j])
                            return false;
                return true;
            }

            bool operator!= (const Matrix<T>& other) const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                if (size != other.getSize())
                    return true;
                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.first; j++)
                        if (this->_values[i][j] != other._values[i][j])
                            return true;
                return false;
            }

            /// @brief "Rotate" or "Invert" a Matrix
            // For example, {
            //                  {1, 2, 3},
            //                  {4, 5, 6},
            //                  {7, 8, 9},
            //              }
            // Becomes  {
            //              {1, 4, 7},
            //              {2, 5, 8},
            //              {3, 6, 9},
            //          }
            // This also means that :
            // `a` == `a.transpose().transpose()`
            /// @return New "transposed" Matrix
            Matrix<T> transpose() const
            {
                std::pair<std::size_t, std::size_t> size = this->getSize();

                if (!size.first ||
                    !size.second)
                    return Matrix<T>();

                Matrix<T> obj({size.second, size.first}, this->_values[0][0]);

                for (std::size_t i = 0; i < size.first; i++)
                    for (std::size_t j = 0; j < size.second; j++)
                        obj._values[j][i] = this->_values[i][j];
                return obj;
            }

            Matrix<T> dot(const Matrix<T>& other) const
            {}

            friend std::ostream& operator<<(std::ostream& os, const Math::Matrix<T>& obj)
            {
                os << obj.str();
                return os;
            }
    };
}

#endif
