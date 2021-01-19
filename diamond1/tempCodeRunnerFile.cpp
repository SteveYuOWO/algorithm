rintf("%04d: Checked\n", tmp);
            } else {
                m[tmp] = 1;
                if(i == 0) printf("%04d: Mystery Award\n", tmp);
                else if(is_prime(i)) printf("%04d: Minion\n", tmp);
                else printf("%04d: Chocolate\n", tmp);
            }