<?php

use PHPUnit\Framework\TestCase;
use App\Validate;

class ValidateTest extends TestCase {
    public function test_email() {
        //TEST EMAIL CORRECTO
        $email = Validate::email('mail@domain.com');
        $this->assertTrue($email);

        //TEST EMIAL INCORRECTO
        $email = Validate::email('mail@@domain.com');
        $this->assertFalse($email);
    }

    public function test_url() {
        //TEST URL CORRECTO
        $url = Validate::url('https://google.com');
        $this->assertTrue($url);

        //TEST URL INCORRECTO
        $url = Validate::url('google.com');
        $this->assertFalse($url);
    }

    public function test_pass() {
        //TEST PASSWORD CORRECTO
        $pass = Validate::pass('0192837');
        $this->assertTrue($pass);

        //TEST PASSWORD INCORRECTO
        $pass = Validate::pass('01noval29');
        $this->assertFalse($pass);
    }
}