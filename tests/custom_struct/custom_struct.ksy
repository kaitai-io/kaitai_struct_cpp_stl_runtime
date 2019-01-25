meta:
  id: custom_struct
  title: Custom Struct
  endian: be
doc: |
  This is a custom struct.
  It contains u1, s1, u2be, u2le, s2be, s2le, u4be, u4le, s4be, s4le,
  u8be, u8le, s8be, s8le, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b24,
  magic, bytes, string, enum, (custom_type), (repeat), (expression).
seq:
  - id: v_u1
    type: u1
  - id: v_s1
    type: s1
  - id: v_u2be
    type: u2be
  - id: v_u2le
    type: u2le
  - id: v_s2be
    type: s2be
  - id: v_s2le
    type: s2le
  - id: v_u4be
    type: u4be
  - id: v_u4le
    type: u4le
  - id: v_s4be
    type: s4be
  - id: v_s4le
    type: s4le
  - id: v_u8be
    type: u8be
  - id: v_u8le
    type: u8le
  - id: v_s8be
    type: s8be
  - id: v_s8le
    type: s8le
  - id: v_b1
    type: b1
  - id: v_b2
    type: b2
  - id: v_b3
    type: b3
  - id: v_b4
    type: b4
  - id: v_b5
    type: b5
  - id: v_b6
    type: b6
  - id: v_b7
    type: b7
  - id: v_b8
    type: b8
  - id: v_b9
    type: b9
  - id: v_b10
    type: b10
  - id: v_b24
    type: b24
  - id: v_magic
    contents: 'CUSTOM'
  - id: v_bytes
    size: 3
  - id: v_string
    type: str
    size: 3
    encoding: ASCII
  - id: v_enum
    type: u1
    enum: enum_type1
  - id: v_custom_type
    type: custom_type1
  - id: v_repeat1_count
    type: u1
  - id: v_repeat1
    type: custom_type1
    repeat: expr
    repeat-expr: v_repeat1_count
  - id: v_repeat2_count
    type: u1
  - id: v_repeat2
    type: custom_type1
    repeat: expr
    repeat-expr: v_repeat2_count / 2
types:
  custom_type1:
    seq:
      - id: magic
        contents: 'CUSTOM_TYPE1'
      - id: version
        type: str
        size: 1
        encoding: ASCII
  custom_type2:
    seq:
      - id: magic
        contents: 'CUSTOM_TYPE2'
      - id: version
        type: str
        size: 2
        encoding: ASCII
enums:
  enum_type1:
    0x01: enum_type1_item1
    0x02: enum_type1_item2
    0x03: enum_type1_item3
  enum_type2:
    0x01: enum_type2_item1
    0x02: enum_type2_item2
    0x04: enum_type2_item3
