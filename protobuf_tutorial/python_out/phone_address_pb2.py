# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: phone_address.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='phone_address.proto',
  package='phone_address',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x13phone_address.proto\x12\rphone_address\"[\n\x07Persion\x12\x11\n\x04name\x18\x01 \x01(\tH\x00\x88\x01\x01\x12\x0f\n\x02id\x18\x02 \x01(\x05H\x01\x88\x01\x01\x12\x12\n\x05\x65mail\x18\x03 \x01(\tH\x02\x88\x01\x01\x42\x07\n\x05_nameB\x05\n\x03_idB\x08\n\x06_emailb\x06proto3'
)




_PERSION = _descriptor.Descriptor(
  name='Persion',
  full_name='phone_address.Persion',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='phone_address.Persion.name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='id', full_name='phone_address.Persion.id', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='email', full_name='phone_address.Persion.email', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='_name', full_name='phone_address.Persion._name',
      index=0, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
    _descriptor.OneofDescriptor(
      name='_id', full_name='phone_address.Persion._id',
      index=1, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
    _descriptor.OneofDescriptor(
      name='_email', full_name='phone_address.Persion._email',
      index=2, containing_type=None,
      create_key=_descriptor._internal_create_key,
    fields=[]),
  ],
  serialized_start=38,
  serialized_end=129,
)

_PERSION.oneofs_by_name['_name'].fields.append(
  _PERSION.fields_by_name['name'])
_PERSION.fields_by_name['name'].containing_oneof = _PERSION.oneofs_by_name['_name']
_PERSION.oneofs_by_name['_id'].fields.append(
  _PERSION.fields_by_name['id'])
_PERSION.fields_by_name['id'].containing_oneof = _PERSION.oneofs_by_name['_id']
_PERSION.oneofs_by_name['_email'].fields.append(
  _PERSION.fields_by_name['email'])
_PERSION.fields_by_name['email'].containing_oneof = _PERSION.oneofs_by_name['_email']
DESCRIPTOR.message_types_by_name['Persion'] = _PERSION
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Persion = _reflection.GeneratedProtocolMessageType('Persion', (_message.Message,), {
  'DESCRIPTOR' : _PERSION,
  '__module__' : 'phone_address_pb2'
  # @@protoc_insertion_point(class_scope:phone_address.Persion)
  })
_sym_db.RegisterMessage(Persion)


# @@protoc_insertion_point(module_scope)