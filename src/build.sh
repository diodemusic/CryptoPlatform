echo "Compiling..."
g++ -o ../build/MerkelRex.out main.cpp MerkelMain.cpp OrderBookEntry.cpp --std=c++11
echo "Running..."
./../build/MerkelRex.out
