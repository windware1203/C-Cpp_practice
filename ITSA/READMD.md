# ITSA 2023/03/15題解
:::info
- **Author: [name=武田奈々]**
- **GUN C++**
- [**題目**](https://github.com/windware1203/C-Cpp_practice/blob/main/ITSA/ITSA_202303.pdf)
- [**解答code**](https://github.com/windware1203/C-Cpp_practice/tree/main/ITSA)
- 喔對了，我沒存code；所以這是我事後憑印象寫的 :D ~~歡迎鞭打~~
- ~~我希望身邊不要一堆不會寫程式的人(麻瓜或アホ)~~
:::
## P1[$_{code}$](https://github.com/windware1203/C-Cpp_practice/blob/main/ITSA/ITSA%20(1).cpp)
> 這題水題蓋章。

本題的字串會讀取空格，直到換行結束；因此需使用`getline()` 來進行整行讀取。
但是前面使用了`cin` 來讀字串個數 $N$，若直接使用 `getline()` 會造成緩衝區(buffer) 內資料未清除；因此需要添加 `string tmp; getline(cin, tmp);` 進行buffer清除再進行字串讀取。然後直接輸出字串長度就好了~

接著，要去除重複字元可使用C++ **STL**的[`set`](https://cplusplus.com/reference/set/set/)來進行處理即可，`set`內不會有重複的元素，再輸出`set`的size即為答案。

## P2[$_{code}$](https://github.com/windware1203/C-Cpp_practice/blob/main/ITSA/ITSA%20(2).cpp)
這題規定要能組成「XY」，意即XY個數相同且X位於Y的前方；若符合輸出 $Yes$，反之則輸出 $No$。

這題我採用先紀錄 $X$ 之個數，再由 $Y$ 來判斷是否合法。
若讀取到 $X$ 則直接紀錄個數，若是 $Y$ 則判斷 $X$ 的個數是否小於 $0$，若小於 $0$ 代表 $Y$ 前面沒有 $X$，即不合法，直接輸出並跳離迴圈；若大於0，則將 $X$ 個數減一，繼續比較，直到迴圈終止。
若迴圈終止後，$X\,Y$ 個數皆為0，則表示此為合法字串。

## P3[$_{code}$](https://github.com/windware1203/C-Cpp_practice/blob/main/ITSA/ITSA%20(3).cpp)
> 好水

判斷是否時間 $\geq 1500$，依據超過的時間去算 $500$ 的倍數，然後加加減減就對ㄌ。
## P4[$_{code}$](https://github.com/windware1203/C-Cpp_practice/blob/main/ITSA/ITSA%20(4).cpp)

這題也沒太難的地方，資料放陣列，迴圈跑陣列查，輸出。

這題我建了一個 `struct` 來存商品的各個資訊，多個商品就開個陣列存。
根據第一個參數決定要查哪個欄位，然後各自使用一個for loop去找，找到就輸出，找不到就`404`。

## P5[$_{code}$](https://github.com/windware1203/C-Cpp_practice/blob/main/ITSA/ITSA%20(5).cpp)
> 高一排列組合

這題就排列組合，用 `recursion` 去模擬即可。

下面這是我寫的 recursive function $F$：
```cpp
int f(int get,int now)
{
    if(get > now)return 0;
    if(get == now)return 1;
    return f(1,now-get)+f(2,now-get);
}
```
`get`為這次取多少沙包，`now` 為目前還要拿的沙包數量。
若 `get` $>$ `now` 就代表不能這樣拿，所以return 0；若相等就直接拿了，不用再拆。
其他狀況就是要繼續呼叫，記得 `now` 欄位要減掉本次已經拿的數量 `get`。

## P6
- 我沒寫出來QQ，拜託教我。

## P7[$_{code}$](https://github.com/windware1203/C-Cpp_practice/blob/main/ITSA/ITSA%20(7)%20.cpp)

***注意:這題數量成長快，要開 `int64_t` 或 `long long int`***
> 取代array 的好東西，[vector](https://cplusplus.com/reference/vector/vector/)

這題其實觀察出規律後，答案就出來了。

一開始有一隻幼體A，一個月後會長成完成體A，第二個月後會生一個幼體B，第三個月A生完一個幼體C就死了，則B長成完整體...直到永遠... $_{自..己..看..題..目...}$

最後只要輸出幼體數量，因此我們只要記錄每個月成體與幼體的數量即可。

經過觀察，我們可以得到以下規律：
1. 成體個數會是上一個月的幼體+上一個月的成體
2. 幼體個數是上一個月的成體
3. 幼體經過三個月後生完幼體後（才）會死

這裡要注意第三點，幼體經過三個月後生完幼體後才會死，所以再算本月成體數量時，仍然要記錄這個月後會死的成體，待存入陣列後再殺死。如下方：
```cpp
big_num = big[i-1] + small[i-1];
small_num = big[i-1];

big.push_back(big_num);
small.push_back(small_num);

if(i >= 3) big[i] -= small[i-3];
```
幼體經過三個月後生完幼體後會死。易言之，這個月死亡的成體數量是前三個月的幼體數量，而且從第三個月開始才有成體會死亡。

最後把這個所求月份的幼體數量輸出，即為答案。
