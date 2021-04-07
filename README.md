# 사전 학습

## 뮤텍스 & 세마포어

[화장실 비유 설명](https://worthpreading.tistory.com/90)

## 왜 약간의 delay를 유발한것인가?

- 새니타이저! 컴파일 옵션을 넣고 돌리면, 굉장히느려진다. 이 부분 문제!
- am_i_dead 함수안의 while문에서 millisecond 단위(sleep_for_ms(1)) 가 아닌 micro second 단위로 (usleep(1))로 변경해주어 잡았다.

- **핵심! 무한 while 문 안에서 usleep(1) ~ usleep(10) 정도를 걸어주어서 while문의 부하를 줄여주니 수 밀리초 정도 딜레이를 유발하는 이슈가 해결되었다!!