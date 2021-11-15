g++ ucantinhos.cpp -o ucantinhos
echo "Teste 1: "
./ucantinhos < test1.in | grep "3" && echo -e "PASSED\n" || echo -e "FAILED\n"
echo "Teste 2: "
./ucantinhos < test2.in | grep "13" && echo -e "PASSED\n" || echo -e "FAILED\n"
echo "Teste 3: "
./ucantinhos < test3.in | grep "257" && echo -e "PASSED\n" || echo -e "FAILED\n"
