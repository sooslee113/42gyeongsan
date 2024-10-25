#include "phillospher.h"

/*
Module containint setters_getters
to avoid writing LOCK UNLOCK everywhere
 */

void    set_bool(t_mutex *mutex, bool *dest, bool value)
{
    safe_mutex_handle(mutex, LOCK);
    *dest = value;
    safe_mutex_handle(mutex, UNLOCK);
}

bool    get_bool(t_mutex *mutex, bool *value) // 안전하게 읽기
{
    bool ret;
    
    safe_mutex_handle(mutex, LOCK);
    ret = *value;
    safe_mutex_handle(mutex, UNLOCK);
    return (ret);
}

void    set_long(t_mutex *mutex, long *dest, long value)
{
    safe_mutex_handle(mutex, LOCK);
    *dest = value;
    safe_mutex_handle(mutex, UNLOCK);
}

long    get_long(t_mutex *mutex, long *value) // 안전하게 읽기
{
    long ret;
    
    safe_mutex_handle(mutex, LOCK);
    ret = *value;
    safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}

bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
/*
주석에 나와 있는 setters_getters 모듈이 LOCK과 UNLOCK을 매번 직접 작성하는 것을 피하려고 사용된다는 내용인데, 
그 이유는 코드의 가독성과 재사용성을 높이고, 동기화 작업을 실수 없이 안전하게 처리하기 위함입니다. 
이 방식은 주로 멀티스레드 환경에서 공유 자원에 접근할 때 발생하는 **경쟁 상태(Race Condition)**나 데드락(Deadlock) 문제를 예방하는 데 도움이 됩니다.

이유 분석:
동기화의 일관성 보장: 멀티스레드 프로그래밍에서는 공유 자원에 접근할 때마다 LOCK과 UNLOCK을 사용하는 것이 필수입니다. 
하지만 매번 일일이 LOCK과 UNLOCK을 코드에 추가하면, 실수로 LOCK을 걸지 않거나 UNLOCK을 놓칠 수 있습니다. 
이를 방지하기 위해, setters_getters 모듈을 사용하여 접근할 때마다 자동으로 LOCK과 UNLOCK을 처리할 수 있도록 만들면 실수를 줄일 수 있습니다.

가독성 향상: LOCK과 UNLOCK을 여러 곳에서 수동으로 작성하는 것은 코드가 길어지고 복잡해지는 원인이 됩니다. 
setters_getters 함수 내부에서 이를 처리하면, 코드가 훨씬 깔끔해지고 유지보수가 쉬워집니다. 
예를 들어, 각각의 자원 접근에 대해 동기화를 직접 처리하는 대신, 세터/게터 함수 안에서만 LOCK/UNLOCK을 하면 그 과정이 추상화되어 코드가 더 명확해집니다.

재사용성: 동기화 작업을 함수로 모듈화하면, 공유 자원에 접근하는 방식이 표준화되며 여러 곳에서 쉽게 재사용할 수 있습니다. 
LOCK과 UNLOCK을 포함한 기능이 하나의 함수에 캡슐화되면, 다른 부분에서도 이 함수를 호출해 동일한 동작을 반복할 수 있으므로 중복을 줄일 수 있습니다.
*/