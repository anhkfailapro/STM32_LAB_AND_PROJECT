#include "main.h"
#include "task.h"
#include "scheduler.h"

void SCH_Init() {
	SCH_TASK_LIST.numofTask = 0;
	for (int i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_TASK_LIST.TASK_QUEUE[i].Delay = 0;
		SCH_TASK_LIST.TASK_QUEUE[i].Period = 0;
		SCH_TASK_LIST.TASK_QUEUE[i].RunMe = 0;
		SCH_TASK_LIST.TASK_QUEUE[i].pTask = 0;
	}
}

void insert(sTask task) {
	if (SCH_TASK_LIST.numofTask == 0) {
		SCH_TASK_LIST.TASK_QUEUE[0] = task;
		SCH_TASK_LIST.numofTask++;
		return;
	}

	int pos = 0;
	int prev_val = SCH_TASK_LIST.TASK_QUEUE[0].Delay;
	int total_val = prev_val;

	while (pos < SCH_TASK_LIST.numofTask && task.Delay > total_val) {
		pos++;
		if (pos < SCH_TASK_LIST.numofTask) {
			prev_val = total_val;
			total_val += SCH_TASK_LIST.TASK_QUEUE[pos].Delay;
		}
	}

	if (pos == SCH_TASK_LIST.numofTask) {
		task.Delay -= total_val;
		SCH_TASK_LIST.TASK_QUEUE[pos] = task;
		SCH_TASK_LIST.numofTask++;
		return;
	}

	for (int j = SCH_TASK_LIST.numofTask; j > pos; j--) {
		SCH_TASK_LIST.TASK_QUEUE[j] = SCH_TASK_LIST.TASK_QUEUE[j - 1];
	}

	if (pos == 0) {
		SCH_TASK_LIST.TASK_QUEUE[0] = task;
		total_val = 0;
		prev_val = task.Delay;
	} else {
		task.Delay -= prev_val;
		total_val = prev_val;
		prev_val += task.Delay;
		SCH_TASK_LIST.TASK_QUEUE[pos] = task;
	}

	total_val += SCH_TASK_LIST.TASK_QUEUE[pos + 1].Delay;
	SCH_TASK_LIST.TASK_QUEUE[pos + 1].Delay = total_val - prev_val;
	SCH_TASK_LIST.numofTask++;
}

void SCH_Add_Task(void (*pFunction)(), uint32_t delay, uint32_t period) {
	if (SCH_TASK_LIST.numofTask >= SCH_MAX_TASKS) return;

	sTask temp;
	temp.pTask = pFunction;
	temp.Delay = delay / TICK;
	temp.Period = period / TICK;
	temp.RunMe = 0;

	insert(temp);
}

void SCH_Update() {
	if (!SCH_TASK_LIST.TASK_QUEUE[0].pTask) return;

	if (SCH_TASK_LIST.TASK_QUEUE[0].Delay == 0) {
		SCH_TASK_LIST.TASK_QUEUE[0].RunMe++;
		if (SCH_TASK_LIST.TASK_QUEUE[0].Period) {
			SCH_TASK_LIST.TASK_QUEUE[0].Delay = SCH_TASK_LIST.TASK_QUEUE[0].Period;
		}
	} else {
		SCH_TASK_LIST.TASK_QUEUE[0].Delay--;
	}
}

void SCH_Delete_Task() {
	int index = 0;
	int flag = 0;
	sTask temp;

	if (SCH_TASK_LIST.TASK_QUEUE[0].Period) {
		flag = 1;
		temp = SCH_TASK_LIST.TASK_QUEUE[0];
	}

	for (; index < SCH_TASK_LIST.numofTask - 1; index++) {
		SCH_TASK_LIST.TASK_QUEUE[index] = SCH_TASK_LIST.TASK_QUEUE[index + 1];
	}

	SCH_TASK_LIST.TASK_QUEUE[index].pTask = 0;
	SCH_TASK_LIST.TASK_QUEUE[index].Delay = 0;
	SCH_TASK_LIST.TASK_QUEUE[index].Period = 0;
	SCH_TASK_LIST.TASK_QUEUE[index].RunMe = 0;
	SCH_TASK_LIST.numofTask--;

	if (flag) insert(temp);
}

void SCH_Dispatch_Tasks() {
	for (int i = 0; i < SCH_MAX_TASKS; i++) {
		if (SCH_TASK_LIST.TASK_QUEUE[i].RunMe > 0) {
			(*SCH_TASK_LIST.TASK_QUEUE[i].pTask)();
			SCH_TASK_LIST.TASK_QUEUE[i].RunMe--;
			SCH_Delete_Task();
		}
	}
}
