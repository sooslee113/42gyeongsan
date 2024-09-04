/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <sooslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:50:05 by sooslee           #+#    #+#             */
/*   Updated: 2024/09/03 16:59:08 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "practice.h"

int mails = 0;

void* routine()
{
    for (int i = 0; i < 100000; i++)
    {        
        mails ++;
        // 이 함수가 작동되는 과정
        // 1. read mails 메일을 읽는다.
        // 2. increment 증가
        // 3. write mail ㅇ 
    }

}

int main(int argc, char **argv)
{
    pthread_t p1, p2;
    if (pthread_create(&p1, NULL, &routine, NULL) != 0)
    {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0)
    {
        return 2;
    }
    if (pthread_join(p1, NULL))
    {
        return 3;
    }
    if (pthread_join(p2, NULL))
    {
        return 4;
    }
    printf("the number of mails : %d\n", mails);
}