if defined __TABLES
else
__TABLES equ 1

macro seg name:0, base:0, limit:0, flags:0, access:0 {
name = $-@b
    if name eq ZERO
        dq 0
    else
        dw (limit) AND 0ffffh
        dw (base) AND 0ffffh
        db ((base) SHR 10h) AND 0ffh
        db access
        db (((limit) SHR 10h) AND 0fh) OR (flags SHL 4h)
        db (((base) SHR 18h) AND 0ffh)
    end if
}

macro ivc segment:0, offset:0, type:0eh, DPL:0, present:1 {
    dw offset AND 0ffffh
    dw segment
    db 0h
    db type OR (DPL SHL 5h) OR (present SHL 7h)
    dw (offset SHR 10h) AND 0ffffh
}

TABLE_NAME equ _

macro table name {
    TABLE_NAME equ name
@@:
}

macro endt {
    TABLE_NAME:
        dw TABLE_NAME - @b
        dd @b
}

end if
