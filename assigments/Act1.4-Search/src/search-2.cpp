#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<char, int> encontrarUnicoSecuencial(const string& s) {
    int comparaciones = 0;
    for (size_t i = 0; i < s.length(); i += 2) {
        comparaciones++;
        if (i == s.length() - 1 || s[i] != s[i + 1]) {
            return make_pair(s[i], comparaciones);
        }
    }
    return make_pair('?', 0); 
}

pair<char, int> encontrarUnicoBinario(const string& s, int inicio, int fin, int& comparaciones) {
    if (inicio > fin) return make_pair('?', 0);
    if (inicio == fin) return make_pair(s[inicio], comparaciones);
    
    int medio = inicio + (fin - inicio) / 2;
    if (medio % 2 == 0) {
        comparaciones++;
        if (s[medio] == s[medio + 1]) {
            return encontrarUnicoBinario(s, medio + 2, fin, comparaciones);
        } else {
            return encontrarUnicoBinario(s, inicio, medio, comparaciones);
        }
    } else {
        comparaciones++;
        if (s[medio] == s[medio - 1]) {
            return encontrarUnicoBinario(s, medio + 1, fin, comparaciones);
        } else {
            return encontrarUnicoBinario(s, inicio, medio - 1, comparaciones);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    for (size_t i = 0; i < strings.size(); i++) {
        int compSecuencial = 0;
        pair<char, int> resultadoSecuencial = encontrarUnicoSecuencial(strings[i]);
        int compBinario = 0;
        pair<char, int> resultadoBinario = encontrarUnicoBinario(strings[i], 0, strings[i].length() - 1, compBinario);

        cout << resultadoSecuencial.first << " " << resultadoSecuencial.second << " ";
        cout << resultadoBinario.first << " " << compBinario << endl;
    }

    return 0;
}

