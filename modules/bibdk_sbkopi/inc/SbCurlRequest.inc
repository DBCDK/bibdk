<?php
/**
 * @file
 * Class for making curl request to SB webservices
 */

/**
 * Class SbCurlRequest
 *
 * Converts parameters to xml that is expected by SB, and posts a request
 */
class SbCurlRequest extends MicroCURL {

  private $url, $request;

  /**
   * Construct a new request
   *
   * @param $request
   * @param $parameters
   * @param $xmlns
   * @param NULL $url
   */
  public function __construct($request, $parameters, $xmlns, $url = NULL) {
    $this->url = $url;
    parent::microcurl();
    $this->setRequest($request, $xmlns);
    $this->setParameters($parameters);
    $this->set_post_xml($this->getPostXml());
  }

  /**
   * Make request
   *
   * @return string
   */
  public function call() {
    return $this->get($this->url);
  }

  /**
   * Return request params as xml string
   *
   * @return mixed
   */
  public function getPostXml() {
    return $this->request->asXML();
  }

  /**
   * Add parameters as children to request xml
   *
   * @param $parameters
   */
  private function setParameters($parameters) {
    foreach ($parameters as $key => $value) {
      $this->request->addChild($key, $value);
    }
  }

  /**
   * Set the request parent element
   *
   * @param $request
   * @param $xmlns
   */
  private function setRequest($request, $xmlns) {
    $this->request = new SimpleXMLElement("<$request/>");
    $this->request->addAttribute("xmlns", $xmlns);
  }

  /**
   * Get reponse code from request
   *
   * The state of the request is defined på http code
   *
   * 204 : order is placed
   * 4xx/5xx: order failed
   *
   * @return mixed
   */
  public function getReponse() {
    return $this->get_status('http_code');
  }
}

/**
 * Class SbCurlRequestException
 *
 * Exception for sb curl requests
 */
class SbCurlRequestException extends Exception {

  private $params;

  /**
   * Set array of parameters
   *
   * @param array $params
   */
  public function setParams(array $params) {
    $this->params = $params;
  }

  /**
   * Get array of parameters
   *
   * @return mixed
   */
  public function getParams() {
    return $this->params;
  }
}
