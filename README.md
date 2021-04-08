# 사전 학습

## 뮤텍스 & 세마포어

[화장실 비유 설명](https://worthpreading.tistory.com/90)

## 왜 약간의 delay를 유발한것인가?

- 새니타이저! 컴파일 옵션을 넣고 돌리면, 굉장히느려진다. 이 부분 문제!
- am_i_dead 함수안의 while문에서 millisecond 단위(sleep_for_ms(1)) 가 아닌 micro second 단위로 (usleep(1))로 변경해주어 잡았다.

- **핵심! 무한 while 문 안에서 usleep(1) ~ usleep(10) 정도를 걸어주어서 while문의 부하를 줄여주니 수 밀리초 정도 딜레이를 유발하는 이슈가 해결되었다!!



## 리펙토링을 위한 전체 흐름 및 구조 잡기



### 핵심 기능 흐름

> - 인자 파싱 (parse.c)
>   - 인자 유효성 검사 (if (is_valid_arguments)) 
>   - 인자 설정 구조체에 저장 (parse_argument)
>     - 설정 구조체 t_setup
> - 실험 준비 (prepare_experiment.c)
>   - 철학자들 초기화 (init_philosophers)
>     - 
>   - 설정 구조체에 실험 준비 데이터 초기화 (init_semaphore)
> - 실험 진행 (run_experiment.c)
>   - 각 철학자를 자식 프로세스로 분기 > 철학자들의 일을 시키기
>   - 관리자 프로세스는 각 철학자의 프로세스가 종료되었을 때, 해당 종료코드를 통해 종료 상황을 구별하도록
>     - case1 : Must_eat_count 가 정해져 있고, must_eat_count로 종료되었을 때 full_philo_count == num_philo 가 되었을 때 exit (0)
>     - case2 : exit_code 가 someone_dead 일 때 exit(1)
> - 뒷 정리
>   - 사용한 semaphore 닫아주기, 동적할당 한 것들 할당 해제 해주기



```c
typedef struct	s_setup
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_each_must_eat;
	t_timeval	time_start_experiment;
	sem_t	*fork_sema;
	sem_t	*print_sema;
	sem_t	*dead_sema;
}			t_setup;

typedef struct	s_philo
{
	int			number;
	int			ate_count;
	t_timeval	time_last_ate;
	t_setup	*setup;
	t_status	status;
}								t_philo;
```

