def to_binary(N):
    
    if N <2 :
        return f'{N}'
    return to_binary(N//2)+f'{N%2}'
        
N = int(input())
print(to_binary(N))