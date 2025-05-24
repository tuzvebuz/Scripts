using System;
using System.Net.Http;
using System.Reflection;
using System.Threading.Tasks;
using System.Text.Json;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace TicTacToe
{
    
    class Program
    {
         static async Task Request()
        {
            using (HttpClient client = new HttpClient())
            {
                Console.WriteLine("Hello World! Which currency would you like to convert?");
                string currency_frm = Console.ReadLine();
                Console.WriteLine("To Which currency would you like to convert?");
                string currency_to = Console.ReadLine();
                string url = $"https://v6.exchangerate-api.com/v6/56b61b3fca6d0a029ee7bad0/latest/{currency_frm}";
                HttpResponseMessage response = await client.GetAsync(url);
                Console.WriteLine(response.ToString());
                if (response.IsSuccessStatusCode)
                {
                    string content = await response.Content.ReadAsStringAsync();
                    Console.WriteLine(content);
                }
                else
                {
                    Console.WriteLine("Failed.");
                }
            }
            
        }

        public async Task Awaitables()
        {
            await Request();
        }
    }
}