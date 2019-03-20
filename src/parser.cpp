#include "parser.h"

Token curr;
MultiTable tablePolinoms;

bool isCommand(string str)
{
    return ((str == "set") || (str == "del") || (str == "get"));
}

double error(const string& s) {
    cerr << "error: " << s << endl;
    return 1;
}

Token_value get_token()
{
    char ch;

    do {
        if (!cin.get(ch)) return curr.tok_value = END;
    } while (ch != '\n' && isspace(ch));

    switch (ch) {

    case ';':
    case '\n':
        return curr.tok_value = PRINT;
    case '+': case '-': case '*': case '(': case ')':
        return curr.tok_value = Token_value(ch);
    default:
        if (isalpha(ch)) {
            curr.string_value = ch;
            while (cin.get(ch) && isalnum(ch)) {
                curr.string_value.push_back(ch);
            }
            cin.putback(ch);
            return curr.tok_value = NAME;
        }
        error("bad token");
        return curr.tok_value = PRINT;
    }
}

Polynomial expr(bool get)
{
    Polynomial left = term(get);

    for (; ; ) {
        switch (curr.tok_value) {
            case PLUS: {
                left += term(true);
                break;
            }
            case MINUS: {
                left -= term(true);
                break;
            }
            default:
                return left;
        }
    }
}

Polynomial term(bool get)
{
    Polynomial left = prim(get);

    for (; ; ) {
        switch (curr.tok_value) {
            case MUL: {
                left *= prim(true);
            }
            default:
                return left;   
        }
    }
    
}


void set(const string& name)
{
    Polynomial q(name);
    cin >> q;
    tablePolinoms.Insert(q);
}

void del(const string& name)
{
    tablePolinoms.Delete(name);
}

void get(const string& name)
{
    cout << endl << tablePolinoms[name];
}

void call(string name)
{
    get_token();
    if (curr.tok_value != LP) throw Exception("'(' excepted");

    get_token();
    if (curr.tok_value != NAME) throw Exception("name polynomial expected");
    string namePolynomial = curr.string_value;

    if (isCommand(namePolynomial)) throw Exception("incorrect polynomial name");

    get_token();
    if (curr.tok_value != RP) throw Exception("')' excepted");

    if (name == "set") {
        set(namePolynomial);
    }
    else if (name == "del") {
        del(namePolynomial);
    }
    else if (name == "get") {
        get(namePolynomial);
    }
}

Polynomial prim(bool get)
{
    if (get) get_token();

    for (; ; ) {
        switch (curr.tok_value) {
            case NAME: {
                string name = curr.string_value;
                if (isCommand(name)) {
                    call(name);
                }
                else {
                    Polynomial q = tablePolinoms[name];
                    return q;
                }
            }
            case LP: {
                Polynomial p = expr(true);
                if (get_token() != RP) {
                    throw Exception("excepted ')'");
                }
                get_token();  // eat ')'
                return p;
            }
            default:
                throw Exception("primary excepted");

        }
    }
}