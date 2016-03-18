
  type

     ps_aes_algo = (ps_CBC_ENC,ps_CBC_DEC,ps_CTR_ENC,ps_CTR_DEC,ps_CCM_ENC,ps_CCM_DEC);

     ps_aes_keytypes = (ps_KEYSLOT_0D,ps_KEYSLOT_2D,ps_KEYSLOT_31,
                        ps_KEYSLOT_38,ps_KEYSLOT_32,ps_KEYSLOT_39,
                        ps_KEYSLOT_2E,ps_KEYSLOT_INVALID,ps_KEYSLOT_36);

  function psInit:int32_t;cdecl;external;
  function psExit:int32_t;cdecl;external;

  { PS_EncryptDecryptAes()
  About: Is an interface for the AES Engine, you can only use predetermined keyslots though.
  Note: Does not support AES CCM, see PS_EncryptSignDecryptVerifyAesCcm()
  
    size			size of data
    in			input buffer ptr
    out			output buffer ptr
    aes_algo		AES Algorithm to use, see ps_aes_algo
    key_type		see ps_aes_keytypes
    iv			ptr to the CTR/IV (This is updated before returning)
   }
  function PS_EncryptDecryptAes(size:u32; in:pu8; out:pu8; aes_algo:u32; key_type:u32; 
             iv:pu8):int32_t;cdecl;external;

  { PS_EncryptSignDecryptVerifyAesCcm()
  About: Is an interface for the AES Engine (CCM Encrypt/Decrypt only), you can only use predetermined keyslots though.
  Note: When encrypting, the output buffer size must include the MAC size, when decrypting, the input buffer size must include MAC size.
  MAC: When decrypting, if the MAC is invalid, 0xC9010401 is returned. After encrypting the MAC is located at inputbufptr+(totalassocdata+totaldatasize)
  
    in			input buffer ptr
    in_size		size of input buffer
    out			output buffer ptr
    out_size		size of output buffer
    data_len		length of data to be crypted
    mac_data_len	length of data associated with MAC
    mac_len		length of MAC
    aes_algo		AES Algorithm to use, see ps_aes_algo
    key_type		see ps_aes_keytypes
    nonce			ptr to the nonce
   }
  function PS_EncryptSignDecryptVerifyAesCcm(in:pu8; in_size:u32; out:pu8; out_size:u32; data_len:u32; 
             mac_data_len:u32; mac_len:u32; aes_algo:u32; key_type:u32; nonce:pu8):int32_t;cdecl;external;

  { PS_GetLocalFriendCodeSeed()
  About: Gets a 64bit console id, it's used for some key slot inits
  
    seed			ptr to where the seed is written to
   }
  function PS_GetLocalFriendCodeSeed(seed:pu64):int32_t;cdecl;external;

  { PS_GetDeviceId()
  About: Gets a 32bit device id, it's used for some key slot inits
  
    device_id		ptr to where the device id is written to
   }
  function PS_GetDeviceId(device_id:pu32):int32_t;cdecl;external;
