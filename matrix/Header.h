#pragma once

class Matrix3x3
{
    public:
        Matrix3x3()
        {
            values = new int* [size];

            for (int i = 0; i < size; i++)
            {
                values[i] = new int[size];
                for (int j = 0; j < size; j++)
                    values[i][j] = 0;
            }
        }
        ~Matrix3x3()
        {
            for (int i = 0; i < size; i++)
                delete[] values[i];
            delete[] values;
        }

        const int element(const int i, const int j)
        {
            return values[i][j];
        }

        void setElement(const int i, const int j, const int value)
        {
            values[i][j] = value;
        }

        void fillRandomElements(const int minVal, const int maxVal)
        {
            srand(time(NULL));
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    values[i][j] = rand() % (maxVal * 2 ) + minVal;
        }

        void print()
        {
            srand(time(NULL));
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    std::cout << values[i][j] << '\t';
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        const int sumPrincipalDiag()
        {
            int sum = 0;
            for (int i = 0; i < size; i++)
                sum += values[i][i];
            return sum;
        }

        const int sumSecondaryDiag()
        {
            int sum = 0;
            for (int i = 0; i < size; i++)
                sum += values[i][2 - i];
            return sum;
        }

        const int productPrincipalDiag()
        {
            int result = 1;
            for (int i = 0; i < size; i++)
                result *= values[i][i];
            return result;
        }

        const int productSecondaryDiag()
        {
            int result = 1;
            for (int i = 0; i < size; i++)
                result *= values[i][2 - i];
            return result;
        }

        const int sumRow(const int iRow)
        {
            int sum = 0;
            for (int j; j < size; j++)
                sum = values[iRow][j];
            return sum;
        }

        const int minColumn(const int iCol)
        {
                int min = values[0][iCol];

                for (int i = 1; i < size; i++)
                    if (min > values[i][iCol])
                        min = values[i][iCol];
                return min;
        }

        const int maxColumn(const int iCol)
        {
            int max = values[0][iCol];

            for (int i = 1; i < size; i++)
                if (max < values[i][iCol])
                    max = values[i][iCol];
            return max;
        }
           

    private:
        int **values;
        int size = 3;
};

class MatrixXnX
{
    public:
        MatrixXnX(const int iDim)
        {
            this->size = iDim;
            values = new int* [iDim];

            for (int i = 0; i < iDim; i++)
            {
                values[i] = new int[iDim];
                for (int j = 0; j < iDim; j++)
                    values[i][j] = 0;
            }
        }
        ~MatrixXnX()
        {
            for (int i = 0; i < size; i++)
                delete[] values[i];
            delete[] values;
        }

        const int element(const int i, const int j)
        {
            return values[i][j];
        }

        void setElement(const int i, const int j, const int value)
        {
            values[i][j] = value;
        }

        void fillRandomElements(const int minVal, const int maxVal)
        {
            srand(time(NULL));
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    values[i][j] = rand() % (maxVal * 2 ) + minVal;
        }

        void print()
        {
            srand(time(NULL));
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                    std::cout << values[i][j] << "  ";
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        const int sumPrincipalDiag()
        {
            int sum = 0;
            for (int i = 0; i < size; i++)
                sum += values[i][i];
            return sum;
        }

        const int sumSecondaryDiag()
        {
            int sum = 0;
            for (int i = 0; i < size; i++)
                sum += values[i][size - 1 - i];
            return sum;
        }

        const int productPrincipalDiag()
        {
            int result = 1;
            for (int i = 0; i < size; i++)
                result *= values[i][i];
            return result;
        }

        const int productSecondaryDiag()
        {
            int result = 1;
            for (int i = 0; i < size; i++)
                result *= values[i][size - 1 - i];
            return result;
        }

        const int sumRow(const int iRow)
        {
            int sum = 0;
            for (int j; j < size; j++)
                sum = values[iRow][j];
            return sum;
        }
        
        const int minColumn(const int iCol)
        {
            int min = values[0][iCol];

            for (int i = 1; i < size; i++)
                if (min > values[i][iCol])
                    min = values[i][iCol];
            return min;
        }

        const int maxColumn(const int iCol)
        {
            int max = values[0][iCol];

            for (int i = 1; i < size; i++)
                if (max < values[i][iCol])
                    max = values[i][iCol];
            return max;
        }

    private:
        int **values;
        int size;
};

template<typename T>
class linkedList
{
	public:
		linkedList()
		{
			this->_head = nullptr;
			this->_tail = nullptr;
			this->_count = 0;
		};

		~linkedList()
		{
			clear();
		}

		void add(T value)
		{
			ListNode<T>* temp = new ListNode<T>;
			temp->value = value;
			temp->next = nullptr;

			if (_head == nullptr)
			{
				_head = temp;
				_head->next = nullptr;
			}
			else
				_tail->next = temp;
			_tail = temp;
			this->_count++;
		}

		bool contains(T value)
		{
			ListNode<T>* current = _head;
			ListNode<T>* previous = new ListNode<T>;

			while (current->next != nullptr)
			{
				previous = current;
				current = current->next;

				if (current->value == value)
					return true;
			}
			return false;
		}

		int count()
		{
			return this->_count;
		}		

		void removeDuplicates()
		{
			if (_head == nullptr)
				return;
			
			ListNode<T>* current = _head;
			
			while (current != nullptr)
			{
				ListNode<T>* runner = current;
				while (runner->next != nullptr)
				{
					if (runner->next->value == current->value)
					{
						ListNode<T>* temp = runner->next->next;
						delete runner->next;
						runner->next = nullptr;
						_count--;
						if (temp != nullptr)
							runner->next = temp;
					}
					else
						runner = runner->next;
				}
				current = current->next;
			}
		}

		T findFromBack(int index)
		{
			if (index > _count)
				return T();

			int counter = 0;
			int itemIndex = this->_count - index;

			ListNode<T>* temp = _head;
			while (counter != itemIndex)
			{
				temp = temp->next;
				counter++;
			}
			return temp->value;
		}

		bool remove(T value)
		{
			ListNode<T>* current = _head;
			ListNode<T>* previous = new ListNode<T>;

			while (current->next != nullptr)
			{
				previous = current;
				current = current->next;

				if (current->value == value)
				{
					previous->next = current->next;
					delete current;
					_count--;
					return true;
				}
			}
			return false;
		}

		void clear()
		{
			if (_head == nullptr)
				return;

			ListNode<T>* tmp;
			while (_head != nullptr)
			{
				tmp = _head-> next;
				delete _head;
				_head = tmp;
				_count = 0;
			}
		}

		void print()
		{		
			if (_head == nullptr)
			{
				cout << "none";
				return;
			}

			ListNode<T>* temp = _head;

			while (temp != nullptr)
			{
				cout << temp->value << "  ";
				temp = temp->next;
			}
			cout << endl;
		}

	private:

		template<typename T>
		class ListNode
		{
			public:
				ListNode()
				{
					this->value = T();
					this->next = nullptr;
				};

				ListNode(T value, ListNode<T>* next)
				{
					this->value = value;
					this->next = next;
				};

				T value;
				ListNode<T>* next;
		};

		ListNode<T>* _head;
		ListNode<T>* _tail;
		int _count;
};