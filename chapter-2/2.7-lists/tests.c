#include "lists.c"

char *names[] = {
    "Georgi",
    "Pesho",
    "Bai Tosho"};

int assert_list(Nameval *list, char **expected_names, int expected_names_size);

int test_addend(Nameval *list)
{
    char *expected_names[] = {
        "Georgi",
        "Pesho",
        "Bai Tosho",
        "Gosho" /* this is inserted at the end */
    };

    list = addend(list, newitem("Gosho", 0));

    return assert_list(list, expected_names, sizeof(expected_names) / sizeof(expected_names[0]));
}

int test_addfront(Nameval *list)
{
    char *expected_names[] = {
        "Gosho", /* this is inserted at the front */
        "Georgi",
        "Pesho",
        "Bai Tosho",
    };

    list = addfront(list, newitem("Gosho", 0));

    return assert_list(list, expected_names, sizeof(expected_names) / sizeof(expected_names[0]));
}

int test_insert_after(Nameval *list)
{
    char *expected_names[] = {
        "Georgi",
        "Pesho",
        "Gosho", // inserted after Pesho in the test
        "Bai Tosho"};

    int res = insert_after(list, "Pesho", newitem("Gosho", 0));
    if (res != 1)
    {
        printf("[ERROR] Got (%d) response code from `insert_after`, expected 1\n", res);
        return 1;
    }

    return assert_list(list, expected_names, sizeof(expected_names) / sizeof(expected_names[0]));
}

int test_insert_after_noexist(Nameval *list)
{
    int res = insert_after(list, "NO_EXIST", newitem("who cares", 0));
    if (res != 0)
    {
        printf("[ERROR] Got (%d) response code from `insert_after` when element is not present, expected 0\n", res);
        return 1;
    }

    Nameval *el = lookup(list, "who cares");
    if (el != NULL)
    {
        printf("[ERROR] Found element \"who cares\" in the list, expected to not be inserted.\n");
        return 1;
    }

    return assert_list(list, names, sizeof(names) / sizeof(names[0]));
}

int test_insert_before(Nameval *list)
{
    char *expected_names[] = {
        "Georgi",
        "Gosho", // inserted before Pesho in the test
        "Pesho",
        "Bai Tosho"};

    int res = insert_before(list, "Pesho", newitem("Gosho", 0));
    if (res != 1)
    {
        printf("[ERROR] Got (%d) error code from `insert_after`, expected 1\n", res);
        return 1;
    }

    return assert_list(list, expected_names, sizeof(expected_names) / sizeof(expected_names[0]));
}

int test_insert_before_noexist(Nameval *list)
{
    int res = insert_before(list, "NO_EXIST", newitem("who cares", 0));
    if (res != 0)
    {
        printf("[ERROR] Got (%d) response code from `insert_before` when element is not present, expected 0\n", res);
        return 1;
    }

    Nameval *el = lookup(list, "who cares");
    if (el != NULL)
    {
        printf("[ERROR] Found element \"who cares\" in the list, expected to not be inserted.\n");
        return 1;
    }

    return assert_list(list, names, sizeof(names) / sizeof(names[0]));
}

int test_merge(Nameval *list)
{
    char *expected_names[] = {
        "Georgi",
        "Pesho",
        "Bai Tosho",
        "Bai Tosho",
        "Pesho",
        "Georgi",
    };

    Nameval *second_list = NULL;
    second_list = addfront(second_list, newitem(names[0], 0));
    second_list = addfront(second_list, newitem(names[1], 0));
    second_list = addfront(second_list, newitem(names[2], 0));

    Nameval *merged_list = merge(list, second_list);

    return assert_list(merged_list, expected_names, sizeof(expected_names) / sizeof(expected_names[0]));
}

int test_merge_null(Nameval *list)
{
    Nameval *merged = merge(list, NULL);

    return assert_list(merged, names, sizeof(names) / sizeof(names[0]));
}

int test_delitem(Nameval *list)
{
    char *expected_names[] = {
        "Georgi",
        /* "Pesho", - THIS IS THE DELETED ITEM*/
        "Bai Tosho"};

    int res = delitem(list, "Pesho");
    if (res != 1)
    {
        printf("[ERROR] Got (%d) response code from delitem, expected 1 when item is deleted", res);
        return 1;
    }

    return assert_list(list, expected_names, sizeof(expected_names) / sizeof(expected_names[0]));
}

int test_delitem_noexist(Nameval *list)
{
    int res = delitem(list, "NOT EXIST");
    if (res != 0)
    {
        printf("[ERROR] Got (%d) response code from delitem, expected 0 when item is not deleted", res);
        return 1;
    }

    return assert_list(list, names, sizeof(names) / sizeof(names[0]));
}

int test_lookup(Nameval *list)
{
    Nameval *res = lookup(list, "Pesho");
    if (strcmp(res->name, "Pesho") != 0)
    {
        printf("[ERROR] Got (%s) for lookup(list, \"Pesho\", expected \"Pesho\"\n", res->name);
        return 1;
    }

    res = lookup(list, "Gosho");
    if (res != NULL)
    {
        printf("[ERROR] Got (%s) for lookup(list, \"Gosho\", expected NULL for non-existing element", res->name);
        return 1;
    }

    return 0;
}

int test_lookup_noexist(Nameval *list)
{
    Nameval *res = lookup(list, "Gosho");
    if (res != NULL)
    {
        printf("[ERROR] Got (%s) for lookup(list, \"Gosho\", expected NULL for non-existing element", res->name);
        return 1;
    }

    return 0;
}

int test_copy(Nameval *list)
{
    Nameval *res = copy(list);

    return assert_list(res, names, sizeof(names) / sizeof(names[0]));
}

int test_apply_incounter(Nameval *list)
{
    int i = 0;
    apply(list, incounter, &i);

    if (i != 3)
    {
        printf("[ERROR] Got (%d) for `i` in `apply(list, incounter, &i)`, expected to be 3\n", i);
        return 1;
    }

    return 0;
}

int assert_list(Nameval *list, char **expected_names, int expected_names_size)
{
    for (int i = 0; i < expected_names_size; i++, list = list->next)
    {
        if (list == NULL)
        {
            printf("[ERROR] list is NULL, expected more elements\n");
            return 1;
        }
        if (strcmp(list->name, expected_names[i]) != 0)
        {
            printf("[ERROR] Got (%s) for name, expected (%s), i=%d\n", list->name, expected_names[i], i);
            return 1;
        }
    }

    return 0;
}

int test(int (*fn)(Nameval *), char *description)
{
    Nameval *list = NULL;
    list = addend(list, newitem(names[0], 0));
    list = addend(list, newitem(names[1], 0));
    list = addend(list, newitem(names[2], 0));

    int res = fn(list);
    if (res == 0)
        printf(" ✅ %s\n", description);
    else
        printf(" ❌ %s\n", description);

    freeall(list);

    return res;
}

int main()
{
    int res = 0;
    res += test(test_addend, "Adding element to the end of the list.");
    res += test(test_addfront, "Adding element to the front of the list.");
    res += test(test_insert_after, "Adding element after a certain element.");
    res += test(test_insert_after_noexist, "Adding element after a certain element that does not exist.");
    res += test(test_insert_before, "Adding element before a certain element.");
    res += test(test_insert_before_noexist, "Adding element before a certain element that does not exist.");
    res += test(test_merge, "Merging two lists.");
    res += test(test_merge_null, "Merging two lists, when one of the them is NULL.");
    res += test(test_delitem, "Deleting an item from the list.");
    res += test(test_delitem_noexist, "Deleting a non-existent item from the list.");
    res += test(test_lookup, "Looking up an item from the list.");
    res += test(test_lookup_noexist, "Looking up a non-existing item from the list.");
    res += test(test_copy, "Copy a list.");
    res += test(test_apply_incounter, "Count the element in a list, via the functions `apply` and `incounter`");

    if (res == 0)
        printf(" ✅✅✅ All the test were executed succesfully. ✅✅✅\n");
    else
        printf(" ❌❌❌There were %d failures❌❌❌\n", res);

    return res;
}