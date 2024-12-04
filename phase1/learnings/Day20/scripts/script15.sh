sed -n 7,8p ../../Day18/cpp_v0/crud01.cpp > ../../Day18/cpp_v0/crud01/Const.h
sed -n 10,15p ../../Day18/cpp_v0/crud01.cpp > ../../Day18/cpp_v0/crud01/BookingManager.h  

sed -n 1,1p ../../Day18/cpp_v0/crud01.cpp > ../../Day18/cpp_v0/crud01/Main.cpp
echo "#include \"Const.h\"" >> ../../Day18/cpp_v0/crud01/Main.cpp
echo "#include \"BookingManager.h\"" >> ../../Day18/cpp_v0/crud01/Main.cpp
sed -n 3,4p ../../Day18/cpp_v0/crud01.cpp >> ../../Day18/cpp_v0/crud01/Main.cpp
sed -n 21,58p ../../Day18/cpp_v0/crud01.cpp >> ../../Day18/cpp_v0/crud01/Main.cpp
