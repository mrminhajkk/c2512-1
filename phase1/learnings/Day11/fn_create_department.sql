CREATE OR REPLACE FUNCTION fn_create_department(
    p_department_name IN VARCHAR2
)
RETURN NUMBER  -- Function will return the department_id
IS
    v_department_id NUMBER := 1;
    v_department_count NUMBER := 0;
BEGIN
    -- Read department count to check if the department exists
    SELECT COUNT(*) INTO v_department_count 
    FROM departments 
    WHERE name = p_department_name;

    -- Use a savepoint for transaction control
    SAVEPOINT start_transaction;

    -- If department exists, get the department_id
    IF v_department_count >= 1 THEN
        SELECT id INTO v_department_id 
        FROM departments 
        WHERE name = p_department_name;
    ELSE
        -- If department doesn't exist, generate new id and insert
        SELECT NVL(MAX(id), 0) + 1 INTO v_department_id 
        FROM departments;

        INSERT INTO departments(id, name)
        VALUES (v_department_id, p_department_name);

        DBMS_OUTPUT.PUT_LINE('Department ' || p_department_name || ' is added');
    END IF;

    COMMIT;  -- Commit the transaction

    -- Return the department_id
    RETURN v_department_id;

EXCEPTION
    WHEN OTHERS THEN
        ROLLBACK TO start_transaction;  -- Rollback in case of an error
        DBMS_OUTPUT.PUT_LINE('Error occurred in creating department: ' || SQLERRM);
        RETURN NULL;  -- Return NULL if an error occurs
END;


-- Test the function
DECLARE
    v_department_id NUMBER;
BEGIN
    v_department_id := fn_create_department('Sales');
    DBMS_OUTPUT.PUT_LINE('Department ID: ' || v_department_id);

    v_department_id := fn_create_department('Marketing');
    DBMS_OUTPUT.PUT_LINE('Department ID: ' || v_department_id);

    v_department_id := fn_create_department('HR');
    DBMS_OUTPUT.PUT_LINE('Department ID: ' || v_department_id);
END;