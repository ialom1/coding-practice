<?
$metadata['https://mail.sust.com/service/extension/samlreceiver '] = array (
  'entityid' => 'https://mail.sust.com/service/extension/samlreceiver ',
  'contacts' => 
  array (
  ),
  'metadata-set' => 'saml20-sp-remote',
  'AssertionConsumerService' => 
  array (
    0 => 
    array (
      'Binding' => 'urn:oasis:names:tc:SAML:2.0:bindings:HTTP-POST',
      'Location' => 'https://mail.sust.com/service/extension/samlreceiver',
      'index' => 0,
    ),
  ),
  'SingleLogoutService' => 
  array (
  ),
  'NameIDFormat' => 'urn:oasis:names:tc:SAML:1.1:nameid-format:unspecified',
  'validate.authnrequest' => false,
  'certificate' => 'example.org.crt',
);


// https://idp.sust.com/simplesaml/saml2/idp/SSOService.php?spentityid=https://mail.sust.com/service/extension/samlreceiver
// https://idp.sust.com/simplesaml/saml2/idp/SingleLogoutService.php?ReturnTo=https://sp1.sust.com