#include "Heap.h"

void init_heap(Heap * ph)
{
	ph -> num_data = 0;
}

BOOL is_empty(Heap * ph)
{
	if (ph -> num_data == 0)
		return TRUE;
	else
		return FALSE;
}

inline int get_parent_index(int idx)
{
	return idx / 2;
}

inline int get_left_child_index(int idx)
{
	return 2 * idx;
}

inline int get_right_child_index(int idx)
{
	return 2 * idx + 1;
}

int get_high_priority_child_index(Heap * ph, int idx)
{
	// �ڽĳ�尡 �������� �ʴ� ��� 
	if (get_left_child_index(idx) > ph -> num_data)
		return 0;
	// ���ʿ��� �ڽĳ�尡 �����ϴ� ��� 
	if (get_left_child_index(idx) == ph -> num_data)
		return get_left_child_index(idx);
		
	// ���� ��� �ڽĳ�尡 �����ϴ� ��� 
	if (ph -> heap_arr[get_left_child_index(idx)].pr
		> ph -> heap_arr[get_right_child_index(idx)].pr)
		return get_right_child_index(idx);
	else
		return get_left_child_index(idx);
}

void insert_heap(Heap * ph, HData data, Priority pr)
{
	int index = ph -> num_data + 1;
	HeapElement new_element= {pr, data};
	
	// ��Ʈ��� �������� 
	while (index != 1) {
		// ���ο� ����� �켱������ �۴�(����)
		// ���� �ִ� ��带 �� ���� ���� 
		if (pr < (ph -> heap_arr[get_parent_index(index)].pr)) {
			ph -> heap_arr[index] = ph -> heap_arr[get_parent_index(index)];
			index = get_parent_index(index);
		}
		
		else
			break;
	}
	
	ph -> heap_arr[index] = new_element;
	ph -> num_data++;
}

HData delete_heap(Heap * ph)
{
	HData       del_data     = (ph -> heap_arr[1]).data;
	HeapElement last_element = ph -> heap_arr[ph -> num_data];
	
	int parent_index = 1;
	int child_index;
	
	while (child_index = get_high_priority_child_index(ph, parent_index)) {
		if (last_element.pr <= ph -> heap_arr[child_index].pr)
			break;
			
		ph -> heap_arr[parent_index] = ph -> heap_arr[child_index];
		parent_index = child_index;
	}
	
	ph -> heap_arr[parent_index] = last_element;
	ph -> num_data--;
	return del_data;
}
