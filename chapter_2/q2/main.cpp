int readNumber();
void writeAnswer(int ans);

int main() {
    int x{readNumber()};
    int y{readNumber()};
    writeAnswer(x+y);
}