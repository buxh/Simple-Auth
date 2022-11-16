# Simple Auth
https://solo.to/buxh
 
## Disclaimer
- This is by no means good and could get cracked rather quickly by anyone with a brain. 
- Made over a year ago in under 20 minutes when I was learning the basics of C++
that's why the code is shit :)

## Note
To make this more secure, use [xor](https://github.com/JustasMasiulis/xorstr) or [skCrypter](https://github.com/skadro-official/skCrypter) to encrypt all plaintext strings, add more [anti-debugging](https://github.com/search?l=C%2B%2B&q=antidebug&type=Repositories) techniques and obfuscate with a good protector like [themida](https://www.oreans.com/Themida.php) or [vmprotect](https://vmpsoft.com/).

## Features
 - Simple, easy to use client-side auth
 - Very small
 - Anti-debugging technique
 - Cross-platform
 - HWID Locked
 - Bad Code!
 - ~~Network Check~~ *removed since it's client side*
## Sample
```c++
int main() 
{
    auth::antidebugger();
    auth::networkCheck();
    auth::hwidCheck();
    
    if (!auth::access) {
        // enter your code
        std::cout << "Hello World" << std::endl;
        while (true) { auth::antidebugger(); }
    }

    return std::cin.get();
}
```

## Help
If you are in need of help open an issue or contact me on discord: `envy#4339`
