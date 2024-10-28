/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooslee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:45:16 by sooslee           #+#    #+#             */
/*   Updated: 2024/10/28 20:54:36 by sooslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillospher.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
	{
		show_error("malloc errror");
		return (NULL);
	}
	return (ret);
}

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		show_error("The value specified by mutex is not valid.");
	else if (EINVAL == status && (INIT == opcode))
		show_error("The value specified by mutex is not valid.");
	else if (EDEADLK == status)
		show_error("A dead lock would occur \
				if the thread blocked waiting for mutex");
	else if (EPERM == status)
		show_error("The current thread does not own the mutex.");
	else if (ENOMEM == status)
		show_error("There is not enough memory to acquire a lock. \
				This errno will only occur in the private path.");
	else if (EPERM == status)
		show_error("The current thread does not own the mutex.");
	else if (EBUSY == status)
		show_error("Mutex is locked");
}

void	safe_mutex_handle(t_mutex *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTORY == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		show_error("Mutex has something wrong");
}

static void	handle_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		show_error("No resources to create another thread");
	else if (EPERM == status)
		show_error("The caller dose not appropriate permission");
	else if (EINVAL == status && CREATE == opcode)
		show_error("The value specified by attr is invaild");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		show_error("The value specified by thread is not valid.");
	else if (ESRCH == status)
		show_error("No thread could be found corresponding");
	else if (EDEADLK == status)
		show_error("A deadlock was detected");
}

void	safe_thread_handle(pthread_t *thread, void*(*foo)(void *), \
		void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		handle_thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		handle_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		handle_thread_error(pthread_detach(*thread), opcode);
	else
		show_error("code is Wrong");
}
